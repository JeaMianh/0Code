#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000
int juzhen[MAXSIZE][MAXSIZE]={0};
int visited[MAXSIZE]={0};
int m;
int count = 0;
 
 
typedef struct Queue{
	int key[MAXSIZE];
	int front;
	int rear;
}Queue;
Queue q;
void Enqueue(int i){
	q.key[q.rear]=i;
	q.rear=(q.rear%MAXSIZE)+1;
}
int Dequeue(){
	int k = q.key[q.front];
	q.front=(q.front+1)%MAXSIZE;
	return k;
}
int Empty(){
	if(q.front==q.rear){
		return 1;
	}else{
		return 0;
	}
}
 
void BFS(){
	int i,j;
 
	for(i=0;i<m;i++){
		visited[i]=0;
	}
	q.front=0;
	q.rear=0;
 
	for(i=0;i<m;){
		int k = i;
		if(visited[i]==0){
			visited[i]=1;
			printf("%d ",i+1);
			Enqueue(i);
			while(Empty()==0){
				i = Dequeue();
				for(j=0;j<m;j++){
					if(juzhen[i][j]==1&&visited[j]==0){
						visited[j]=1;
						printf("%d ",j+1);
						Enqueue(j);
					}
				}
			}
			count++;
		}
		i = ++k;
 
	}
}
 
 
int main(){
	int a,b;
	int i,j,k;
 
	scanf("%d",&m);
 
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			scanf("%d",&juzhen[i][j]);
		}
	}
 
	BFS();
	printf("\n");
	printf("%d",count);
	return 0;
}