#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000
int juzhen[MAXSIZE][MAXSIZE]={0};
int visited[MAXSIZE]={0};
int n,m;
int count = 0;
void DFS(int i){
	int j;
	visited[i]=1;
	for(j=0;j<n;j++){
		if(visited[j]==0&&juzhen[i][j]==1){
			DFS(j);
		}
	}
}
 
void DDFS(){
	int i = 0;
	for(i=0;i<n;i++){
		visited[i]=0; //初始化
	}
	for(i=0;i<n;i++){
		if(visited[i]==0){
			DFS(i);
			count++;
		}
	}
	
}
int main(){
	int a,b;
	int i,j,k;
 
	scanf("%d %d",&n,&m);
 
	for(i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			juzhen[a-1][b-1]=juzhen[b-1][a-1]=1;
	}
	DDFS();
	printf("%d",count-1);
	return 0;
}