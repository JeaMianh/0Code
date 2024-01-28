#include<stdio.h>
#include<iostream>
using namespace std;
int degree[100][100]={0};
int visited[100][100]={0};
typedef struct{
	int vexnum;
	int arcs[100][100];
}Graph;
int main()
{
	int n;
	cin>>n;
	Graph G[n];
	int i,j,k;
	for(i=0;i<n;i++)
	{
		cin>>G[i].vexnum;
		for(j=0;j<G[i].vexnum;j++)
		{
			for(k=0;k<G[i].vexnum;k++)
			{
				cin>>G[i].arcs[j][k];
				if(G[i].arcs[j][k]==1) degree[i][k]++;
			}
		}
	}
	int flag=1;
	for(i=0;i<n;i++)
	{
		flag=1;
		for(j=0;j<G[i].vexnum&&flag;j++)
		{
			for(k=0;k<G[i].vexnum;k++)
			{
				flag=0;
				if(degree[i][k]==0&&visited[i][k]!=0)
				{
					visited[i][k]=1;
					for(int m=0;m<G[i].vexnum;m++)
					if(G[i].arcs[k][m]==1) degree[i][m]--;
					flag=1;
					break;
				}
			}
		}
		if(flag==0)
			cout<<1;
		else cout<<0;
	}
	
	return 0;
}
