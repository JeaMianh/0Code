#include<stdio.h>
void warshall(int a[][100], int n) {
	//warshall算法求可达矩阵
	//(1)i＝1；
    //(2)对所有j如果a[j，i]＝1，则对k＝0，1，…，n-1，a[j，k]＝a[j，k]∨a[i，k]；
    //(3)i加1；
    //(4)如果i<n，则转到步骤2，否则停止
    int i, j, k;
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j][i]==1)
			{
				for(k=0;k<n;k++)
				{
					//逻辑加 
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
	printf("输入节点个数:\n");
	scanf("%d",&n);
	printf("输入一个%d阶邻接矩阵:\n", n);
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
		printf("输入错误，矩阵中只能包含0或1!\n");//确认矩阵中有无0，1之外的数字 
		return 1;
	}
	
	warshall(a,n); 
	printf("求得的可达矩阵为：\n");
	printMatrix(a,n);
	
	sum=n*n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			sum1 += a[i][j];
			if(i!=j)
			{
				if(a[i][j]+a[j][i]==0) // 是否是单向连通图 
				{
					flag=1;
				}
			}
		}
	}
	if(sum1==sum)
	{
		printf("这是一个强连通有向图\n");
		return 0;
	} 
	if(flag!=1)
	{
		printf("这是一个单向连通图\n");
		return 0;
	} 
	
	//改造邻接矩阵 
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
	
	printf("改造后的邻接矩阵为：\n");
	printMatrix(b,n);
	
	warshall(b,n); // 求改造后的邻接矩阵的可达矩阵
	printf("改造后的邻接矩阵的可达矩阵为：\n");
	printMatrix(b,n);
	
	flag = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if(i!=j) // 判断是否是弱连通图 
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
		printf("这不是连通有向图\n");
		return 0;
	}
	printf("这是一个弱连通有向图\n");
	
	return 0;
}
