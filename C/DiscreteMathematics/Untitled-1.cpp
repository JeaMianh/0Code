#include <stdio.h>
#include <stdlib.h>

//定义一个函数，用于执行Warshall算法
void warshall(int **a, int n) {
  //a是邻接矩阵，n是顶点个数
  for (int i = 0; i < n; i++) { //遍历每个顶点
    for (int j = 0; j < n; j++) { //遍历每个顶点
      if (a[j][i] == 1) { //如果j可以到达i
        for (int k = 0; k < n; k++) { //遍历每个顶点
          a[j][k] = a[j][k] | a[i][k]; //更新j可以到达的顶点
        }
      }
    }
  }
}

//定义一个函数，用于打印矩阵
void print_matrix(int **a, int n) {
  //a是矩阵，n是行列数
  for (int i = 0; i < n; i++) { //遍历每一行
    for (int j = 0; j < n; j++) { //遍历每一列
      printf("%d ", a[i][j]); //打印元素和空格
    }
    printf("\n"); //换行
  }
}

//主函数
int main() {
  int n; //定义一个变量，用于存储顶点个数
  printf("请输入顶点个数：\n"); //提示用户输入
  scanf("%d", &n); //读取用户输入

  //动态分配内存空间，用于存储邻接矩阵
  int **a = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(sizeof(int) * n);
  }

  printf("请输入邻接矩阵，每行输入%d个0或1，用空格隔开，输入完一行按回车：\n", n); //提示用户输入
  for (int i = 0; i < n; i++) { //遍历每一行
    for (int j = 0; j < n; j++) { //遍历每一列
      scanf("%d", &a[i][j]); //读取用户输入
    }
  }

  printf("你输入的邻接矩阵是：\n"); //输出提示信息
  print_matrix(a, n); //调用函数，打印邻接矩阵

  warshall(a, n); //调用函数，执行Warshall算法

  printf("对应的可达矩阵是：\n"); //输出提示信息
  print_matrix(a, n); //调用函数，打印可达矩阵

  //释放内存空间
  for (int i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);

  return 0; //返回值
}
