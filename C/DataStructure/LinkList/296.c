#include<stdio.h>
int main()
{
	int n,i,j;
	int flag = 1;
	char str[100];
	scanf_s("%d", &n);
	scanf_s("%s", str,100);
	for ( i = 0; i < n/2; i++)
	{
		if (str[i]!=str[n-1-i])flag = 0;
	}
	if (flag)printf("YES");
	else printf("NO");
}
