#include<stdio.h>
#include<string.h>
char a[10005];
int main()
{
	scanf("%s",a);
	int len=strlen(a);
	int i,j,flag;//i记录周期数，j记录下一个周期开始的位置
	for(i=1;i<len;i++)
	{
		if(len%i==0)
		{
			flag=1;
			for(j=i;j<len;j++)//从第二个周期起始位置开始判断
				if(a[j]!=a[j%i])//比较周期中每个数是否相等
				{
					flag=0;
					break;//不相等跳出，周期数加一
				}
		}
			if(flag)//找到周期跳出
			break;
	}
	printf("%d\n",i);
	return 0;
}
