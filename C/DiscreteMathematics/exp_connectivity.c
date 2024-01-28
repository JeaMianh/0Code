#include <stdio.h>
#include <stdlib.h>

// Warshall算法
void warshall(int **a, int n) { // a是邻接矩阵，n是顶点个数
  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      if (a[j][i] == 1) { // 如果j可以到达i
        for (int k = 0; k < n; k++) { 
          a[j][k] = a[j][k] | a[i][k]; // 更新j可以到达的顶点
        }
      }
    }
  }
}

// 判断图的连通性
void connectivity(int **a, int n) { // a是邻接矩阵，n是顶点个数
  int **b = (int **)malloc(sizeof(int *) * n); //创建一个新的矩阵b，用于存储可达矩阵的转置
  for (int i = 0; i < n; i++) {
    b[i] = (int *)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      b[i][j] = a[j][i]; //将a的转置赋值给b
    }
  }

  int **c = (int **)malloc(sizeof(int *) * n); //创建一个新的矩阵c，用于存储可达矩阵的转置与可达矩阵的并集
  for (int i = 0; i < n; i++) {
    c[i] = (int *)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      c[i][j] = a[i][j] | b[i][j]; //将a和b对应位置的元素取逻辑或赋值给c
    }
  }

  int **d = (int **)malloc(sizeof(int *) * n); //创建一个新的矩阵d，用于存储邻接矩阵的转置与邻接矩阵的并集
  for (int i = 0; i < n; i++) {
    d[i] = (int *)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      d[i][j] = a[i][j] | b[i][j]; //将a和b对应位置的元素取逻辑或赋值给d
    }
  }

  int strong = 1; // 标记是否是强连通图
  int weak = 1; // 标记是否是弱连通图
  int single = 1; // 标记是否是单向连通图

  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      if (a[i][j] == 0) { // 如果可达矩阵有一个元素为0
        strong = 0; // 不是强连通图
      }
      if (i != j && c[i][j] == 0) { //如果可达矩阵的转置与可达矩阵的并集除了对角线之外有一个元素为0
        single = 0; //不是单向连通图
      }
    }
  }

  warshall(d, n); // 对邻接矩阵的转置与邻接矩阵的并集执行Warshall算法，得到新的可达矩阵

  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      if (d[i][j] == 0) { // 如果新的可达矩阵有一个元素为0
        weak = 0; // 不是弱连通图
      }
    }
  }

  for (int i = 0; i < n; i++) {
    free(b[i]);
    free(c[i]);
    free(d[i]);
  }
  free(b);
  free(c);
  free(d);

  if (strong == 1) {
    printf("这是一个强连通图\n");
  } else if (single == 1) {
    printf("这是一个单向连通图\n");
  } else if (weak == 1) {
    printf("这是一个弱连通图\n");
  } else {
    printf("这是一个非连通图\n");
  }
}


void print_matrix(int **a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) { 
      printf("%d ", a[i][j]); 
    }
    printf("\n"); 
  }
}


int main() {
  int n; 
  printf("请输入顶点个数：\n"); 
  scanf("%d", &n); 

 
  int **a = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(sizeof(int) * n);
  }

  printf("请输入邻接矩阵，每行输入%d个0或1，用空格隔开，输入完一行按回车：\n", n); 
  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      scanf("%d", &a[i][j]); 
    }
  }

  printf("你输入的邻接矩阵是：\n"); 
  print_matrix(a, n); // 打印邻接矩阵

  warshall(a, n); 

  printf("对应的可达矩阵是：\n"); 
  print_matrix(a, n); // 打印可达矩阵

  connectivity(a, n); 

 
  for (int i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);

  return 0; 
}
