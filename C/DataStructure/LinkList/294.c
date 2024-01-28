#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	int data;
	struct list *next;
}node, *List;
 
void Create(List *p, int n){
	List tail,q;
	int i;
	*p = tail = (List)malloc(sizeof(node));
	(*p)->next = NULL;
	for(i=0; i<n; i++){
		q = (List)malloc(sizeof(node));
		scanf("%d", &q->data);
		q->next = NULL;
		tail->next = q;
		tail = q;
	}	
	q->next = NULL;
}
 
void GetOdd(List p, int n){
	List q;
	int i;
	q = p->next;
	for(i=0; i<n, q!=NULL; i++){
		if( i%2==0 ){
			printf("%d ", q->data);
		}
		q = q->next;
	}
}
 
void GetEven(List p, int n){
	List q;
	int i;
	q = p->next;
	for(i=0; i<n, q!=NULL; i++){
		if( i%2!=0 ){
			printf("%d ", q->data);
		}
		q = q->next;
	}
}
 
int main(){
	List p;
	int n;
	scanf("%d", &n);
	Create(&p, n);
	GetOdd(p, n);
	GetEven(p, n);
	return 0;
} 