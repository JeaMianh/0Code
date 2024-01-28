 #include<stdio.h>
#include<string.h>
int main()
{
	char str[80], i=0;
	gets_s(str, 80);
	while (str[i] != '\0') {
		if (str[i] >= 'a' && str[i] <= 'z') { str[i] -=  32;}
		i++;
	}
	int nu = strlen(str);
	//printf("%d", nu);
	//puts(str); 
	i = 0;
	for (int flag=0,flag1=-1,i = 0; i < nu; ) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			 flag =0,flag1=i;//flag1找到第一个大写字母的地方，flag确定是否已经排过序
			 for (int j = i + 1; j < nu; j++) {
				if (str[j] >= 'A' && str[j] <= 'Z')
				if (str[i] > str[j]) { char ch = str[i]; str[i] = str[j]; str[j] = ch; i = j; flag = 1; }//在找到第二个大写字母后进行排序
				else i++;//如果不大于就让第一个大写字母自增变为第二个大写字母！
			 }i = flag1;//标记第一次出现大写字母的地方，重置
		}
		else i++;
		if (flag == 0&&flag1!=-1)break;//没有找到大写字母，并且在排序次数为0 的时间去停止
	}
	puts(str);
	return 0;
}