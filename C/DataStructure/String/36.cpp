#include <stdio.h>
int main(){
//scanf输入二维数组
	//这样就对二维数组arr[n][n]进行赋值了
	int n;
	scanf("%d\n",&n);
    int arr[n][n], i, j;
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf ("%d", &arr[i][j]);
        }
    }
    int line[10]={0};
	int colum[10]={0}; 
    //每行元素求和 有几行就有几个结果 结果存入数组 
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		line[i]+=arr[i][j];
		}
	}
	//每列元素求和 
	for(j=0;j<n;j++){
    	for(i=0;i<n;i++){
    		colum[j]+=arr[i][j];
		}
	}
	//主对角线元素求和 结果只有一个 用sum直接存 
	int sum1=0;
	for(i=0;i<n;i++){
		sum1+=arr[i][i];
	} 
	//辅对角线求和
	int sum2=0;
	for(i=0,j=n-1;i<n;i++,j--){
		sum2+=arr[i][j];
	}
	//再初始化一个数组把以上结果存进去然后进行比较
	int res[100]; 
	//存行结果
	for(i=0;i<n;i++){
		res[i]=line[i];
	} 
	//存列结果
	for(i=n,j=0;j<n;j++){
		res[i]=colum[j];
		i++;
	}
	//存剩下的两个结果
	res[2*n]=sum1;
	res[2*n+1]=sum2;
	//进行排序 选择冒泡排序 
	int temp=0;
    for (i = 0; i < 2 * n + 1; i++) {
		for (j = 0; j < 2 * n + 1 - i; j++) {
			if (res[j] < res[j + 1]) {
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
			}
		}
	}
	for (i = 0; i <= 2 * n + 1; i++) {
		printf("%d ", res[i]);
	}
	return 0;
}
