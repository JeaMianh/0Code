#include <stdio.h>
int main()
{
	int n = 0;
	scanf("%d",&n);
	int a[n] = {0};
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int low=0,high = n-1;                 
    int temp = a[low];         //暂存枢值 
while(low != high)
 {
 	while(low < high && a[high] >= temp) high --;// 找小于轴值的记录
	 if(low < high) {a[low] = a[high],low++;}    //该记录移动到小下标端
	 while (low < high && a[low] <= temp) low++ ;  //找大于轴值的记录
	 if(low < high) { a[high] = a[low]; high--;   //该记录移动到大下标端 
	 } 	
 }
 a[low] = temp;
 for (int i=0;i<n;i++)
 printf("%d ",a[i]);
 printf("\n");
 return 0;
 } 
