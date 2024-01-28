#include<stdio.h>
int main()
{
	int a[2][3],b[3][2],c[2][2],n=0,m,i,j;  //关键是理解公式，c是2^2的
	for(i=0;i<2;i++)
	for(j=0;j<=2;j++)
	{
		scanf("%d",&a[i][j]);
	}
	for(i=0;i<=2;i++)
	for(j=0;j<2;j++)
	{
		scanf("%d",&b[i][j]);
	}
	for(i=0;i<2;i++)
	for(j=0;j<2;j++)
	{
		n=0;
		for(m=0;m<=2;m++)              //循环要写在内层
		{
			n=n+a[i][m]*b[m][j];      //利用公式和n=0自加
		}
		c[i][j]=n;
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");                   //记得这个换行
	}
	printf("\n");                       //记得这个换行
	for(i=0;i<=2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}