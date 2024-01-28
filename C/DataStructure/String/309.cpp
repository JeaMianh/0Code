#include<stdio.h>
int main()
{
	int a[100][100];
	int b[100][100];
	int n,m,i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		 scanf("%d",&a[i][j]);//获得01矩阵
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]==1)
				scanf("%d",&a[i][j]);//给1所在处的元素赋值
		}
	}
  for(i=0;i<n;i++)//矩阵b一样的操作
	{
		for(j=0;j<m;j++)
		 scanf("%d",&b[i][j]);
	}
  for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(b[i][j]==1)
				scanf("%d",&b[i][j]);
		}
	}
   for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j]=a[i][j]+b[i][j];//加法运算，把结果存储在a矩阵中
		}
	}
   int count=0;
   for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]!=0)
				printf("1 ");//输出01矩阵
			else
				printf("0 ");
			count++;
			if(count%m==0)//换行
				printf("\n");
		}
	}
   for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]!=0)
				printf("%d ",a[i][j]);//输出值
		}
	}
	return 0;
}
