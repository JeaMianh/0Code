#include<stdio.h>
#include<math.h>
#define MaxNum 1010
int main()
{
    int m,i,j,deep,deepest;
    while(scanf("%d",&m)!=EOF && m)       //多点测试输入
    {
        int T[MaxNum];
        for(i=1; i<=m; i++)
            scanf("%d",&T[i]);
        scanf("%d",&deep);
        deepest = (int)(log(m)/log(2))+1; //完全二叉树的深度：根节点为深度1
        if(deep > deepest)
	/*给定深度大于树的最大深度： 输出结点为空*/
            printf("EMPTY\n");
        else
        if(deep == deepest)
        {
	/*给定深度等于树的最大深度： 输出最后一层结点*/
            i = (int)pow(2,deep-1); //最后一层首元素的下标
            for(i=i; i<=m; i++)     //最后一层不一定满
                printf("%d ",T[i]);
            printf("\n");   //注意换行
        }
        else
        {
	/*给定深度小于树的最大深度： 输出中间某层结点*/
            i = (int)pow(2, deep-1); //第deep层的首元素下标为i
            j = (int)pow(2, deep)-1; //第deep层的末元素下标为j（对于完全二叉树来说中间层必定是满的）
            for(i=i; i<=j; i++)
                printf("%d ",T[i]);
            printf("\n");
        }

    }
}
