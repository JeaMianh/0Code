#include <stdio.h>
#include <stdlib.h>

// Warshall�㷨
void warshall(int **a, int n) { // a���ڽӾ���n�Ƕ������
  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      if (a[j][i] == 1) { // ���j���Ե���i
        for (int k = 0; k < n; k++) { 
          a[j][k] = a[j][k] | a[i][k]; // ����j���Ե���Ķ���
        }
      }
    }
  }
}

// �ж�ͼ����ͨ��
void connectivity(int **a, int n) { // a���ڽӾ���n�Ƕ������
  int **b = (int **)malloc(sizeof(int *) * n); //����һ���µľ���b�����ڴ洢�ɴ�����ת��
  for (int i = 0; i < n; i++) {
    b[i] = (int *)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      b[i][j] = a[j][i]; //��a��ת�ø�ֵ��b
    }
  }

  int **c = (int **)malloc(sizeof(int *) * n); //����һ���µľ���c�����ڴ洢�ɴ�����ת����ɴ����Ĳ���
  for (int i = 0; i < n; i++) {
    c[i] = (int *)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      c[i][j] = a[i][j] | b[i][j]; //��a��b��Ӧλ�õ�Ԫ��ȡ�߼���ֵ��c
    }
  }

  int **d = (int **)malloc(sizeof(int *) * n); //����һ���µľ���d�����ڴ洢�ڽӾ����ת�����ڽӾ���Ĳ���
  for (int i = 0; i < n; i++) {
    d[i] = (int *)malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      d[i][j] = a[i][j] | b[i][j]; //��a��b��Ӧλ�õ�Ԫ��ȡ�߼���ֵ��d
    }
  }

  int strong = 1; // ����Ƿ���ǿ��ͨͼ
  int weak = 1; // ����Ƿ�������ͨͼ
  int single = 1; // ����Ƿ��ǵ�����ͨͼ

  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      if (a[i][j] == 0) { // ����ɴ������һ��Ԫ��Ϊ0
        strong = 0; // ����ǿ��ͨͼ
      }
      if (i != j && c[i][j] == 0) { //����ɴ�����ת����ɴ����Ĳ������˶Խ���֮����һ��Ԫ��Ϊ0
        single = 0; //���ǵ�����ͨͼ
      }
    }
  }

  warshall(d, n); // ���ڽӾ����ת�����ڽӾ���Ĳ���ִ��Warshall�㷨���õ��µĿɴ����

  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      if (d[i][j] == 0) { // ����µĿɴ������һ��Ԫ��Ϊ0
        weak = 0; // ��������ͨͼ
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
    printf("����һ��ǿ��ͨͼ\n");
  } else if (single == 1) {
    printf("����һ��������ͨͼ\n");
  } else if (weak == 1) {
    printf("����һ������ͨͼ\n");
  } else {
    printf("����һ������ͨͼ\n");
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
  printf("�����붥�������\n"); 
  scanf("%d", &n); 

 
  int **a = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(sizeof(int) * n);
  }

  printf("�������ڽӾ���ÿ������%d��0��1���ÿո������������һ�а��س���\n", n); 
  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      scanf("%d", &a[i][j]); 
    }
  }

  printf("��������ڽӾ����ǣ�\n"); 
  print_matrix(a, n); // ��ӡ�ڽӾ���

  warshall(a, n); 

  printf("��Ӧ�Ŀɴ�����ǣ�\n"); 
  print_matrix(a, n); // ��ӡ�ɴ����

  connectivity(a, n); 

 
  for (int i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);

  return 0; 
}
