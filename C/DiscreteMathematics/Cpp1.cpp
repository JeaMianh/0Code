#include<stdio.h>

void warshall(int a[][100], int n) {
	//warshall�㷨��ɴ����
	//(1)i��1��
    //(2)������j���a[j��i]��1�����k��0��1������n-1��a[j��k]��a[j��k]��a[i��k]��
    //(3)i��1��
    //(4)���i<n����ת������2������ֹͣ
    int i, j, k;
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j][i]==1)
			{
				for(k=0;k<n;k++)
				{
					//�߼��� 
					if(a[j][k]==1||a[i][k]==1)
					{
						a[j][k]=1;
					}
					else if(a[j][k]==0&&a[i][k]==0)
					{
						a[j][k]=0;
					}
				}
			}
		}
	}
} 

void printMatrix(int a[][100], int n){
	int i,j;
	printf("��õĿɴ����Ϊ��\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) 
		{
			printf("%d ", a[i][j]);
			if(j == 3)
			{
				printf("\n");
			}
		}
	}
}

int connectivity(int a[][100],int n) {
	int sum = n*n;
	int i, j, flag = 0, sum1 = 0;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			sum1++;
			if(i!=j) {
				if(a[i][j] + a[j][i] != 2) {
					flag=1;
				}
			}
		}
	}
	if(sum1 == sum && flag == 0) {
		return 1;
	} else if (flag == 1) {
		return 2;
	} else {
		return 3;
	}
}

int main() {
	int n,i=0,j=0,k=0,flag=0,sum=0,sum1=0;
	int a[100][100]={0};
    int b[100][100]={0};

//	���������ʾ
	printf("Please input the order of the matrix:\n");
	
	scanf("%d",&n);
	printf("please input a matrix with %d * %d:\n",n,n);
    for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
			b[i][j] = a[i][j]; 
			if(a[i][j]!=1&&a[i][j]!=0) {
				flag=1;
			}
		}
	}
	if(flag==1) {
		printf("Get matrix error!Only 0 or 1 in matrix!\n");//ȷ�Ͼ���������0��1֮������� 
		return 1;
	}
	
	warshall(a,n);
	printMatrix(a,n);

	if(connectivity(a,n) == 1) {
		printf("This is a strong connectivity graph.\n");//����һ��ǿ��ͨ����ͼ 
		return 0; 
	} else if (connectivity(a,n) == 2){
		printf("This is a single connectivity diagram.\n");//����һ��������ͨͼ 
		return 0;
	}

	//������ǵ�������ͼ�����ԭ������и���õ��µ��ڽӾ��� 
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(i!=j) {
				if(b[i][j]==1||b[j][i]==1) {
					b[i][j]=1;
					b[j][i]=1;
				}
			}
		}
	}
	
	// ���¾���Ŀɴ���� 
	warshall(b,n);
	printMatrix(b,n);
	if(connectivity(b,n) == 1) {
		printf("This is a weak connectivity graph.\n");//����һ������ͨ����ͼ 
	} else if(connectivity(b,n) == 2){
		printf("This is an unconnected graphs.\n");//�ⲻ����ͨ����ͼ 
	}
	
	return 0;
}
