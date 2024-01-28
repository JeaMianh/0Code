#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 100001
 
//利用静态链表的原理去做 
typedef struct{
	int key;
	int next;
}SLinkList;
 
void InitList(SLinkList* L, int n){
	int i;
	int index,key,next;
	for(i=0; i<n; i++){
		scanf("%d %d %d", &index, &key, &next);
		L[index].key = key;
		L[index].next = next;
	}
}
 
//输出注意格式 
void Print(SLinkList* L, int index, int n){
	int i;
	for(i=0; i<n; i++){
		if(L[index].next == -1){
			printf("%05d %d -1", index, L[index].key);
		}else{
			printf("%05d %d %05d\n", index, L[index].key, L[index].next);
		}
		index = L[index].next;
	}
}
 
//输出注意那个j，他如果执行了删除就留在原地
//主要就是个比较删除的任务 
int Remove(SLinkList *L, int index, int n){
	int i,j;
	int absKey;
	while(index != -1){
		absKey = abs(L[index].key);
		i = L[index].next;
		j = index;
		while(i != -1){
			if(absKey == abs(L[i].key)){
				L[j].next = L[i].next;
				n--;
			}else{
				j = i;
			}
			i = L[i].next;
		}
		index = L[index].next;
	}
	return n;	
}
 
int main(){
	SLinkList L[MAXSIZE];
	int head,n;
	memset(L, -1, sizeof(SLinkList));
	scanf("%d %d", &head, &n);
	InitList(L, n);
	n = Remove(L, head, n);
	printf("%d\n", n);
	Print(L, head, n);
	return 0;
} 