/*哈夫曼树的理解*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n, A[30],i,sum=0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);
    sort(A, A+n);  //从小到大排序找出最小的两个结点
    for(i=1; i <= n-1; i++)
    {
        A[i] = A[i]+A[i-1]; //构造结点
        sum += A[i];          //构造的结点求和即可得出最短带权路径
        sort(A+i-1, A+n);   //将构造的结点重新加入数组等待下次比较
    }
    printf("%d",sum);
}
