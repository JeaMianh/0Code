// Inserting a node at any position
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

//申请节点
Node* NewNode(int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("malloc:");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

//头插法
void InsertAtBeginning(Node** pointerToHead, int x)
{
    Node* newNode = NewNode(x);
    newNode->next = *pointerToHead;
    *pointerToHead = newNode;
}

//尾插法
void InsertAtEnd(Node** pointerToHead, int x)
{
    Node* newNode = NewNode(x);
    if (*pointerToHead == NULL )
    {
        *pointerToHead = newNode;
    }else{
        Node* temp = *pointerToHead;
        while (temp->next != NULL)//头节点为空时，这样写会访问NULL的next，引起segamentation fault
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//指定位置插入
void InsertByPosition(Node** pointerToHead, int position, int x)
{
    Node* newNode = NewNode(x);
    if (position == 1)
    {
        newNode->next = *pointerToHead;
        *pointerToHead = newNode;
        return;
    }
    Node* temp = *pointerToHead;
    for (int i = 0; i < position-2; i++)
    {
         if (temp == NULL)
        {
            printf("Position is out of range.");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position is out of range.");
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
}

void print(Node* head)//此处head是局部变量，直接遍历不会改变头指针
{
    printf("List is:\n");
    while(head != NULL)
    {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;
    printf("How many numbers?\n");
    int n,i,x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the number:\n");
        scanf("%d", &x);
        InsertAtEnd(&head, x);
        print(head);
    }
}