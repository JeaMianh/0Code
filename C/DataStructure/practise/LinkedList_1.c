// Inserting a node at the beginning
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    Node* next;
}Node;

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

// 头部插入节点
// Node* insert(Node* head, int x)//头插之后头节点改变，应返回新的节点
// {
//     Node* temp = (Node*)malloc(sizeof(Node));
//     temp->data = x;
//     temp->next = head;
//     head = temp;
//     return head;
// }

//指针的指针写法。指向指针的地址，所以头节点也改变了
void insert(Node** pointerTohead, int x)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = *pointerTohead;
    *pointerTohead = temp;
}

// 任意位置插入节点

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
        // head = insert(head, x);
        insert(&head, x);//另外一种写法，指针的指针。
        print(head);
    }
}   
    