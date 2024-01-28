#include <stdio.h>
int main()
{
	int a[100],n,m,i,number,x;
	number = 0;
	scanf("%d %d",&n,&m);
	x = n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(x>0)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				number++;
			}
			if(number == m)
			{
				m = a[i];
				a[i] = 0;
				number = 0;
				x--;
				printf("%d ",i);
			}
		}
	}
	return 0;
}
