#include<stdio.h>
#include<stdlib.h>

typedef struct BstNode
{
    int data;
    struct BstNode* left;
    struct BstNode* right;
}BstNode;

// 创建节点
BstNode* NewNode(int x)
{
    BstNode* newNode = (BstNode*)malloc(sizeof(BstNode));
    if (newNode == NULL)
    {
        perror("malloc:");
        exit(-1);
    }
    
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入新节点
void Insert(BstNode** pproot, int data)
{
    if (*pproot == NULL)
    {
        *pproot = NewNode(data);
        return;
    }
    if (data <= (*pproot)->data)
    {// 递归地插入
        Insert(&((*pproot)->left), data);
    }else{
        Insert(&((*pproot)->right), data);
    }
}
/*
Node* Insert(Node* root, int data) {
    if (root == NULL) {
        return NewNode(data);
    }
    if (data < root->data) {
        root->left = Insert(root->left, data);
    } else if (data > root->data) {
        root->right = Insert(root->right, data);
    }
    return root;
*/

// 查找
BstNode* Search(BstNode* proot, int data)
{
    if (proot == NULL || (proot)->data == data)
        return proot;
    if ((proot)->data < data )
        return Search(proot->right, data);
    return Search(proot->left, data);   
}

// 删除
BstNode* Delete(BstNode* proot, int data)
{
    if (proot == NULL)
        return proot;
    if (data < proot->data)
        proot->left = Delete(proot->left, data);
    else if (data > proot->data)
        proot->right = Delete(proot->right, data);
    else{
        if (proot->left == NULL)
        {
            BstNode* temp = proot->right;
            free(proot);
            return temp;
        }else if (proot->right == NULL){
            BstNode* temp = proot->left;
            free(proot);
            return temp;
        }
        // 找到右树中最小的值
        BstNode* temp = proot->right;
        while (temp && temp->left != NULL)
            temp = temp->left;
        proot->data = temp->data;
        proot->right = Delete(proot->right, temp->data);  
    }
    return proot;
}

void inorder(BstNode *proot)
{
    if (proot == NULL)
        return;
    inorder(proot->left);
    printf("%d", proot->data);
    inorder(proot->right);
}

int main()
{
    BstNode* proot = NULL;
    int arr[8] = {5,8,12,7,9,10,11,15};
    for (int i = 0; i < 8; i++)
    {
        Insert(proot, arr[i]);
    }
    inorder(proot);
}