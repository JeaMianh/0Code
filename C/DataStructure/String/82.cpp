#include<stdio.h>
int main()
{
	char n;
	n = getchar();//先给n一个值
	int a=0, b=0, c=0, d=0;
	int step=0;
	while (n!=EOF&&n!='\n'&&n!='\r')//不结束，不回车，不换行，进入循环
	{
		if (n >= 'A' && n <= 'Z')
			a =1;
		else if (n >= 'a' && n <= 'z')
			b=1;
		else if (n >= '0' && n <= '9')
			c=1;
		else 
			d=1;
		step++;
		n = getchar();
	}
	int du=0;
	du = a + b + c + d;
	if (step == 0)//没进入循环
		printf("0");
	else if (step <= 8)//长度小于等于9
		printf("%d", du);
	else //长度大于8
	    printf("%d", du+1);
	return 0;
}