#include <stdio.h>

//����������
int vote(int a, int b, int c, int d, int e)
{
    if(a + b + c + d + e >=3) //���õȼ۹�ʽ
        return 1;
    else
        return 0;
}

//������
int main()
{
    int a,b,c,d,e; //��������������
    printf("��������˵ı����Ը��0��1���ո�ֿ�����");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e); //����������ֵ
    if(vote(a,b,c,d,e)) //���ñ������
        printf("���ͨ��!\n");
    else
        printf("�����ͨ��!\n");
    return 0;
}

