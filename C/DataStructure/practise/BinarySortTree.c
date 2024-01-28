#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* NewNode(int data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* proot, int data)
{
    if (proot == NULL)
    {
        proot = NewNode(data);
        return proot;
    }
    if (data <= proot->data)
    {
        proot->left = Insert(proot->left, data);
    }else{
        proot->right = Insert(proot->right, data);
    }
    return proot;
}

void preorder(Node* proot)
{
    if (proot != NULL)
    {
        printf("%d ",proot->data);
        preorder(proot->left);
        preorder(proot->right);
    }
}

void inorder(Node* proot)
{
	if (proot != NULL)
	{
		inorder(proot->left);
		printf("%d ", proot->data);
		inorder(proot->right);
	}
 } 

int main()
{
    Node *proot = NULL;
    int arr[]={6, 32, 5, 1, 13, 12, 18, 11, 2};
    int len = sizeof(arr)/sizeof(int);
    for (int i = 0; i < len; i++)
    {
        proot = Insert(proot, arr[i]);
    }
    inorder(proot);

    return 0;
}
