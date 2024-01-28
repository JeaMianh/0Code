#include <stdio.h>

//定义表决函数
int vote(int a, int b, int c, int d, int e)
{
    if(a + b + c + d + e >=3) //调用等价公式
        return 1;
    else
        return 0;
}

//主函数
int main()
{
    int a,b,c,d,e; //定义五个输入变量
    printf("输入五个人的表决意愿（0或1，空格分开）：");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e); //输入五个表决值
    if(vote(a,b,c,d,e)) //调用表决函数
        printf("表决通过!\n");
    else
        printf("表决不通过!\n");
    return 0;
}

