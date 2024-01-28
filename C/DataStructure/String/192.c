#include<stdio.h>
#include <stdlib.h>
int main(){
    int a[5]={8,6,5,4,1},b[5];   //重新建立一个数组
    int i;
		for(i=0;i<5;i++){
			b[i]=a[4-i];
		}
	printf("原数组为：\n");
    for(i=0;i<5;i++){
		printf("%d ",a[i]);
    }
	printf("\n");
    printf("逆序排放后为为：\n");
     for(i=0;i<5;i++){
		printf("%d ",b[i]);
    }

	printf("\n");
	system("pause");
	return 0;
}
