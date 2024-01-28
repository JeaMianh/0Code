#include<stdio.h>
int main()
{
	int p,i,j,a[10]={1,2,3,4,5,6,7,8,9,10},b[10]={0};
	scanf("%d",&p);
	for(i=0;i<=p;i++)
	{
		b[i]=a[i];          //将下标0-p的换至B数组的下标0-p中 
	}
	for(i=0;i<=(9-p);i++)
	{
		a[i]=a[i+p+1];
	}
	for(i=(9-p);i<=9;i++)
	{
		a[i]=b[i-(9-p)];    //连错三次，都是因为没搞清楚这些加加减减
	}
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
