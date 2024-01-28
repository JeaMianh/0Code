#include <stdio.h>
#include <stdlib.h>
typedef struct link {
	int id;
	struct link* next;
} LINK;
 
LINK* Creat(int n);
void YueSeFu(LINK* head, int n, int m, int* a);
void DisplyLINK (LINK *head);
 
int main(void) {
	int n, m;//n为总人数，m为出圈时报的数
	scanf("%d%d", &n, &m);
	int a[n];
	LINK* tail = NULL;//定义尾指针
	tail = Creat(n);//创建一个循环链表并得到尾指针
	YueSeFu(tail, n, m, a);
	for (int i = 0; i < n; i++) {//打印出圈顺序（编号）
		printf("%d ", a[i]);
	}
}
 
LINK* Creat(int n) {
	LINK *head = NULL,*p = NULL, *pr = NULL;
	int i;
	for(i = 1;i <= n;i++)
	{
		p = (LINK*)malloc(sizeof(LINK));
		if(p == NULL)
		{
			printf("动态内存分配失败");
			return NULL;
		}
		p->id = i;
		if(head == NULL)
		{
			head = p;
		}
		else
		{
			pr->next = p;
		}
		pr = p;
	}
	p->next = head;
	return pr;
}
 
void YueSeFu(LINK* tail, int n, int m, int* a) {
	int count = 0, sum = 0;
	LINK* p = tail->next, *q = tail;
	while (sum < n - 1) {
		count++;
		if (count == m) {
			q->next = p->next;
			*a = p->id;
			free(p);
			p = q->next;
			count = 0;
			sum++;
			a++;
		} else {
			q=p;
			p=p->next;
		}
	}
	*a = p->id;
	free(p);
}