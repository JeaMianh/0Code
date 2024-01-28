#include<stdio.h>
#include<stdlib.h>
 
typedef struct list{
	int data;
	struct list* next;
}node, *List;
 
//头插法创建链表，这样结果链表也用头插，顺序就会正过来了 
void Create(List *head, int n){
	List p;
	int i;
	*head = (List)malloc(sizeof(node));
	(*head)->next = NULL;
	for(i=0; i<n; i++){
		p = (List)malloc(sizeof(node));
		scanf("%d", &p->data);
		p->next = (*head)->next;
		(*head)->next = p;
	}	
}
 
List Merge(List L1, List L2){
	List head,p1,p2;
	List node;
	head = (List)malloc(sizeof(node));
	head->next = NULL;
	p1 = L1->next;
	p2 = L2->next;
	//这里做去重，谁大让谁存进去往后走，一样大就一起往后走	
	while((p1!=NULL)&&(p2!=NULL)){
		if(p1->data < p2->data){
			node = (List)malloc(sizeof(node));
			node->data = p2->data;
			node->next = head->next;
			head->next = node;
			p2 = p2->next; 
		}else if(p1->data > p2->data){
			node = (List)malloc(sizeof(node));
			node->data = p1->data;
			node->next = head->next;
			head->next = node;
			p1 = p1->next;
		}else{
			node = (List)malloc(sizeof(node));
			node->data = p1->data;
			node->next = head->next;
			head->next = node;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	//如果有剩下的就直接存进去就好 
	while(p1!=NULL){
		node = (List)malloc(sizeof(node));
		node->data = p1->data;
		node->next = head->next;
		head->next = node;
		p1 = p1->next;
	}
	while(p2!=NULL){
		node = (List)malloc(sizeof(node));
		node->data = p2->data;
		node->next = head->next;
		head->next = node;
		p2 = p2->next;
	}
	return head;
}
 
void Print(List head){
	List p = head->next;
	while(p!=NULL){
		printf("%d ", p->data);
		p = p->next;
	}
}
 
int main(){
	int n1, n2;
	List L1, L2, L3;
	scanf("%d %d", &n1, &n2);
	Create(&L1, n1);
	Create(&L2, n2);
	L3 = Merge(L1, L2);
	Print(L3);
	return 0;
} 