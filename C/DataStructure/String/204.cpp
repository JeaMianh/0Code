 
#include<stdio.h>
#include<string.h>
 
void count(char a[], char b[])
{
	int i, j, num = 0;//i标记每个单词的第一位 
	
		for (i = 0; i < strlen(a); )
		{
			int flag = 0; //flag用来统计每个单词和word比较的次数 
			for (j = 0; a[i + j] != ' ' && a[i + j] != '\0'; j++)//注意最后一个单词末尾是'\0'不是' ' 
			{
				if (a[i + j] == b[j])
				{
					flag += 1;
				}
			}
			i = i + j + 1;//i标记下一个单词的开头 
			if (flag == strlen(b)&&j==strlen(b))num++;//如果比较次数和word一样，即单词和word相同，则个数+1		
		}
	printf("%s %d", b, num);
}
 
int main()
{
	char string[100], word[8];
	gets(string);
	gets(word);
	count(string, word);
 
	return 0;
}