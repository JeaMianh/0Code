#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20 //��󶥵���
typedef int Matrix[MAX_SIZE][MAX_SIZE]; //�����������

//������ϵ����
void CreateMatrix(Matrix M, int n) {
    int i, j;
    printf("������%d*%d�Ĺ�ϵ����0��1����\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &M[i][j]); //�������Ԫ��
        }
    }
}

//�����ϵ����
void PrintMatrix(Matrix M, int n) {
    int i, j;
    printf("���%d*%d�Ĺ�ϵ����\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", M[i][j]); //�������Ԫ��
        }
        printf("\n"); //����
    }
}

//��������ϵ����ĺϳ�
void ComposeMatrix(Matrix A, Matrix B, Matrix C, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0; //��ʼ��C����Ԫ��Ϊ0
            for (k = 0; k < n; k++) {
                C[i][j] = C[i][j] || (A[i][k] && B[k][j]); //���������C����Ԫ��
            }
        }
    }
}

int main() {
    Matrix A, B, C; //����������ϵ����
    int n; //���嶥����
    printf("�����붥������\n");
    scanf("%d", &n); //���붥����
    CreateMatrix(A, n); //����A����
    CreateMatrix(B, n); //����B����
    ComposeMatrix(A, B, C, n); //��C����
    PrintMatrix(C, n); //���C����
    return 0;
}

