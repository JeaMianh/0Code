 
#include<stdio.h>
 
int main()
{
	//输入
	int arr[3][3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	//求和
	int* arrp = arr[0];
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += *(arrp + 4 * i);
	}
	//输出
	printf("%d", sum);
	return 0;
}