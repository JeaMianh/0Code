#include<stdio.h>
#include<string.h>
int main()
{
	char a[50];
	gets(a);
	int i, j, k, num = 0;
	/*num用来计数要输出几个
	i从头指到尾，负责移动
	k来标记i原先的位置，负责记录*/
	for (i = 0; i < strlen(a); )
		//遇到字母先输出，再根据后面的数字字符判断再输出几个
	{
		k = i;
		if (a[i] >= '0' && a[i] <= '9')
			//如果为数字字符
		{
			if (a[i + 1] >= '0' && a[i + 1] <= '9')
				//如果它后面的也是数字字符
			{
				num = (a[i] - '0') * 10 + a[i + 1] - '0';
				i += 2;
			}
			else
				//如果它后面的不是数字字符
			{
				num = a[i] - '0';
				i++;
			}
			for (j = 0; j < num - 1; j++)
				//这里num-1是因为之前已经输出过一个
			{
				printf("%c", a[k - 1]);
			}
		}
		else
			//输出一个字符
		{
			printf("%c", a[i]);
			i++;
		}
	}
	return 0;
}