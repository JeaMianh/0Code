#include <stdio.h>

int count = 0; // 结点个数

int Count(int m, int n)
{
    if (2*m <= n) // 左孩子结点
    {
        count++;
        Count(2*m, n); // 递归计算左孩子结点的子结点
    }
    if (2*m+1 <= n) // 右孩子结点
    {
        count++;
        Count(2*m+1, n);// 递归计算右孩子结点的子结点
    }
    return count;
}

int main(void)
{
    int n, m;
    int i = 0;    // 记录共输入多少组数据
    int val[100]; // 储存每组子树的结点个数
    while (scanf("%d %d", &m, &n) == 2 && m != 0 && n != 0)
    {
        val[i++] = Count(m, n) + 1; //  
        count = 0;// 更新count值为0
    }
    for (int j = 0; j < i; j++)
        printf("%d\n", val[j]);
    return 0;
}
