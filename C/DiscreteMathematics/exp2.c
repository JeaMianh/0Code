#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20 //最大顶点数
typedef int Matrix[MAX_SIZE][MAX_SIZE]; //定义矩阵类型

//创建关系矩阵
void CreateMatrix(Matrix M, int n) {
    int i, j;
    printf("请输入%d*%d的关系矩阵（0或1）：\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &M[i][j]); //输入矩阵元素
        }
    }
}

//输出关系矩阵
void PrintMatrix(Matrix M, int n) {
    int i, j;
    printf("输出%d*%d的关系矩阵：\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", M[i][j]); //输出矩阵元素
        }
        printf("\n"); //换行
    }
}

//求两个关系矩阵的合成
void ComposeMatrix(Matrix A, Matrix B, Matrix C, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0; //初始化C矩阵元素为0
            for (k = 0; k < n; k++) {
                C[i][j] = C[i][j] || (A[i][k] && B[k][j]); //按定义计算C矩阵元素
            }
        }
    }
}

int main() {
    Matrix A, B, C; //定义三个关系矩阵
    int n; //定义顶点数
    printf("请输入顶点数：\n");
    scanf("%d", &n); //输入顶点数
    CreateMatrix(A, n); //创建A矩阵
    CreateMatrix(B, n); //创建B矩阵
    ComposeMatrix(A, B, C, n); //求C矩阵
    PrintMatrix(C, n); //输出C矩阵
    return 0;
}

