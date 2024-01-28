#include <stdio.h>
#include<malloc.h>

struct LNode{
	int adress;
	int data;
	int next;
	int flag;//flag作为标志 如果数据绝对值相同，且不是第一次遇到则为0。
}table[100000],newtable[100];

int main()
{
	int num,n,i,site,count=0,t;
	scanf("%d %d",&num,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&site);//输入地址
		scanf("%d %d",&table[site].data,&table[site].next);
		table[site].adress=site;//用地址做下标
		table[site].flag=1;//flag均置为1
	}
	
	int j;
	j=num;
	for(i=0;i<n;i++)
	{
		newtable[i]=table[j];//整理数组，使之按链表顺序排列
		j=table[j].next;
	}
	for(i=0;i<n;i++)//去重（使重复元素flag置为0）
	{
		for(j=i+1;j<n;j++)
		{
			if((newtable[j].data==newtable[i].data||newtable[j].data==-1*(newtable[i].data))&&newtable[j].flag==1)
			{
				newtable[j].flag=0;
			}
	}
	}
	for(i=0;i<n;i++)
	{
		if(newtable[i].flag!=0)
		{ 
            count++;//计算去重后链表长度
		}
		for(j=i+1;j<n;j++)
		{
			if(newtable[j].flag==0)
				continue;
			if(newtable[j].flag==1)
			{
				newtable[i].next=newtable[j].adress;//更新去重后的next数据域
				break;
			}
		}
	}
	printf("%d\n",count);
	for(i=0,t=0;i<n;i++)
	{
		
		if(newtable[i].flag!=0)
		{
			t++;
			if(t<count)//看是否为最后一个输出
			{
				printf("%05d %d %05d\n",newtable[i].adress,newtable[i].data,newtable[i].next);
			
			}
			if(count==t)
			{
				printf("%05d %d",newtable[i].adress,newtable[i].data);
				printf(" -1");//最后一个输出next值为-1
				printf("\n");                                      
			}
			
		}
	}
      return 0;
}


