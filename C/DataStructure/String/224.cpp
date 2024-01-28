#include<stdio.h>
int main()
{
	int array1[2][3],array2[3][2];
		//矩阵用二维数组储存 
	int i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
			scanf("%d",&array1[i][j]);
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			scanf("%d",&array2[i][j]);
	int multi[2][2]={0};
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			for(k=0;k<3;k++)
			{
				multi[i][j]+=(array1[i][k]*array2[k][j]);
					//结果矩阵中第i行、第j列元素，即原矩阵1中第i行和原矩阵2中第j列各元素乘积的和 
					//三重循环实现 
			}
			printf("%d ",multi[i][j]);
		}
		printf("\n");
	}
}