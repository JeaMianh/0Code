#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    Node* left;
    Node* right;
}Node;

Node* NewNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("malloc");
        exit(-1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* proot, int data)
{
    if (proot == NULL)
        return NewNode(data);
    if (data <= proot->data)
    {
        // proot->left = InsertAtEnd(proot,data); Uncorrect
        proot->left = Insert(proot->left,data);
    }else{
        //proot->right = InsertAtEnd(proot,data); 
        proot->right = Insert(proot->right,data);
    }
    return proot; 
}

// level order traversal

void preorder(Node* proot)//DLR
{
    if (proot == NULL)
        return;
    printf("%d ", proot->data);
    preorder(proot->left);
    preorder(proot->right);
}

void inorder(Node* proot)//LDR
{
    if (proot == NULL)
        return;
    inorder(proot->left);
    printf("%d ", proot->data);
    inorder(proot->right);
}

void postorder(Node* proot)//LRD
{
    if (proot == NULL)
        return;
    postorder(proot->left);
    postorder(proot->right);
    printf("%d ", proot->data);
}




int main()
{
    Node* proot = NULL;
}