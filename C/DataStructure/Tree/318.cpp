#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct treenode{
     char data;
     struct treenode *lchild;
     struct treenode *rchild;
 }treenode,*tree;
 
tree createTree(char *preorder,char *inorder,int n);
 void postorderTraverse(tree t);
 int main()
 {
     char preorder[27],inorder[27];
    gets(preorder);
    gets(inorder);
     
     int n;//the number of the vertex
     n=strlen(preorder);
     
     
     tree t;
    t=createTree(preorder,inorder,n);
     //
     postorderTraverse(t);
     return 0;
 }
 tree createTree(char *pre,char *in,int n)
 {
     int k;
     char *p;//指针变量p跟习惯用的i/j/k没有区别
     //if(n<=0) return NULL;
     
     treenode *b=(treenode*)malloc(sizeof(treenode));
     b->data=*pre;
     for(p=in;p<in+n;p++)     {
         if(*p==*pre) break;
     }
     
     k=p-in;
     b->lchild=createTree(pre+1,in,k);
     b->rchild=createTree(pre+k+1,p+1,n-k-1);
     return b;
     
 }
 void postorderTraverse(tree t)
 {
     /*if(!t) printf("EMPTY\n");
     else
     {
         postorderTraverse(t->lchild);
         postorderTraverse(t->rchild);
         printf("%d ", t->data);
     }*/
     if(t)
     {
         postorderTraverse(t->lchild);
         postorderTraverse(t->rchild);
         printf("%c", t->data);
     }
 }