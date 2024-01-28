#include<stdio.h>

int main()
{
    int m,n;//m为查找的节点，n为全部节点个数
    int po,lo;
    int stack[1000];
    int top=-1;
    int count;
    while(scanf("%d %d",&m,&n)&&m!=0&&n!=0){
        count = 0;
        stack[0]=m;
        top++;
        count++;
        while (top!=-1)
        {
            po = 2*stack[top];
            lo = 2*stack[top]+1;
            top--;
            if(po<=n){
                top++;
                stack[top]=po;
                count++;
            }
            if(lo<=n){
                top++;
                stack[top]=lo;
                count++;
            }
            // top--;
        }
        printf("%d\n",count);
    }
    return 0;
}
