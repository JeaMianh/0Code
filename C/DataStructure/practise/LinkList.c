#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node* NewNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void InsertB(Node *phead, int data)
{
    Node *temp = NewNode(data);
    temp->next = phead;
    phead = temp;
}

void InsertE(Node *phead, int data)
{
    Node *newNode = NewNode(data);
    //空表直接插
    if (phead == NULL)
    {
        phead = newNode;
        return;
    }
    Node *temp = phead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    
}

void printLinkList(Node* phead)
{
    while (phead != NULL)
    {
    	printf(" %d",phead->data);
        phead = phead->next;
        
    }
}


int main()
{
    Node* pheadB = NULL;
    Node* pheadE = NULL;
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = sizeof(arr)/sizeof(int);
    for (int i = 0; i < len; i++)
    {
        InsertB(pheadB,arr[i]);
        InsertE(pheadE,arr[i]);
    }
    printLinkList(pheadB);
    printLinkList(pheadE);
    return 0;
}
