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
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) 
		{
			printf("%d ", a[i][j]);
			if(j == n-1)
			{
				printf("\n");
			}
		}
	}
}

int main()
{
	int n,i=0,j=0,k=0,flag=0,sum=0,sum1=0;
	int a[100][100]={0};
	int b[100][100]={0};
	printf("����ڵ����:\n");
	scanf("%d",&n);
	printf("����һ��%d���ڽӾ���:\n", n);
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j] = a[i][j];
			if(a[i][j]!=1&&a[i][j]!=0)
			{
				flag=1;
			}
		}
	}
	if(flag==1)
	{
		printf("������󣬾�����ֻ�ܰ���0��1!\n");//ȷ�Ͼ���������0��1֮������� 
		return 1;
	}
	
	warshall(a,n); 
	printf("��õĿɴ����Ϊ��\n");
	printMatrix(a,n);
	
	sum=n*n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			sum1 += a[i][j];
			if(i!=j)
			{
				if(a[i][j]+a[j][i]==0) // �Ƿ��ǵ�����ͨͼ 
				{
					flag=1;
				}
			}
		}
	}
	if(sum1==sum)
	{
		printf("����һ��ǿ��ͨ����ͼ\n");
		return 0;
	} 
	if(flag!=1)
	{
		printf("����һ��������ͨͼ\n");
		return 0;
	} 
	
	//�����ڽӾ��� 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(b[i][j]==1||b[j][i]==1)
				{
					b[i][j]=1; 
					b[j][i]=1;
				}	
			}
		}
	}
	
	printf("�������ڽӾ���Ϊ��\n");
	printMatrix(b,n);
	
	warshall(b,n); // ��������ڽӾ���Ŀɴ����
	printf("�������ڽӾ���Ŀɴ����Ϊ��\n");
	printMatrix(b,n);
	
	flag = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if(i!=j) // �ж��Ƿ�������ͨͼ 
			{
				if(b[i][j] == 0)
				{
					flag=1;
				}
			}
			
		}
	}
	
	if(flag==1)
	{
		printf("�ⲻ����ͨ����ͼ\n");
		return 0;
	}
	printf("����һ������ͨ����ͼ\n");
	
	return 0;
}
