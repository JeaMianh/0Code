#include<stdio.h>

typedef struct Node
{
    int key;
    int next;
}Node;

Node LinkList[10001];

void Init()
{
    int n, head, adress, next, key;
    scanf("%d %d", &head, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &adress, &key, &next);
        LinkList[adress].key = key;
        LinkList[adress].next = next;
    }
}


int main()
{
    Init();

    


    return 0;
}