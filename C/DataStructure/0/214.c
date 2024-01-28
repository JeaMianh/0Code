#include<stdio.h>
#include<string.h>
void count(char* str, int* nu);
int main()
{
	char string[100];
	int num[5]={0};
	gets_s(string);
	count(string, num);
	for (int j = 0; j < 5; j++)
		printf("%d ", num[j]);
	return 0;
}
void count(char* str, int* nu)
{
	int sum;
	sum=strlen(str);
	for (int i = 0; i < sum; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			nu[0]++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			nu[1]++;
		else if (str[i] == ' ')
			nu[2]++;
		else if (str[i] >= '0' && str[i] <= '9')
			nu[3]++;
		else
			nu[4]++;
	}
}