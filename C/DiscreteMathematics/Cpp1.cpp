#include<stdio.h>

void warshall(int a[][100], int n) {
	//warshall算法求可达矩阵
	//(1)i＝1；
    //(2)对所有j如果a[j，i]＝1，则对k＝0，1，…，n-1，a[j，k]＝a[j，k]∨a[i，k]；
    //(3)i加1；
    //(4)如果i<n，则转到步骤2，否则停止
    int i, j, k;
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j][i]==1)
			{
				for(k=0;k<n;k++)
				{
					//逻辑加 
					if(a[j][k]==1||a[i][k]==1)
					{
						a[j][k]=1;
					}
					else if(a[j][k]==0&&a[i][k]==0)
					{
						a[j][k]=0;
					}
				}
			}
		}
	}
} 

void printMatrix(int a[][100], int n){
	int i,j;
	printf("求得的可达矩阵为：\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) 
		{
			printf("%d ", a[i][j]);
			if(j == 3)
			{
				printf("\n");
			}
		}
	}
}

int connectivity(int a[][100],int n) {
	int sum = n*n;
	int i, j, flag = 0, sum1 = 0;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			sum1++;
			if(i!=j) {
				if(a[i][j] + a[j][i] != 2) {
					flag=1;
				}
			}
		}
	}
	if(sum1 == sum && flag == 0) {
		return 1;
	} else if (flag == 1) {
		return 2;
	} else {
		return 3;
	}
}

int main() {
	int n,i=0,j=0,k=0,flag=0,sum=0,sum1=0;
	int a[100][100]={0};
    int b[100][100]={0};

//	添加输入提示
	printf("Please input the order of the matrix:\n");
	
	scanf("%d",&n);
	printf("please input a matrix with %d * %d:\n",n,n);
    for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
			b[i][j] = a[i][j]; 
			if(a[i][j]!=1&&a[i][j]!=0) {
				flag=1;
			}
		}
	}
	if(flag==1) {
		printf("Get matrix error!Only 0 or 1 in matrix!\n");//确认矩阵中有无0，1之外的数字 
		return 1;
	}
	
	warshall(a,n);
	printMatrix(a,n);

	if(connectivity(a,n) == 1) {
		printf("This is a strong connectivity graph.\n");//这是一个强连通有向图 
		return 0; 
	} else if (connectivity(a,n) == 2){
		printf("This is a single connectivity diagram.\n");//这是一个单向连通图 
		return 0;
	}

	//如果不是单向连接图，则对原矩阵进行改造得到新的邻接矩阵 
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(i!=j) {
				if(b[i][j]==1||b[j][i]==1) {
					b[i][j]=1;
					b[j][i]=1;
				}
			}
		}
	}
	
	// 求新矩阵的可达矩阵 
	warshall(b,n);
	printMatrix(b,n);
	if(connectivity(b,n) == 1) {
		printf("This is a weak connectivity graph.\n");//这是一个弱联通有向图 
	} else if(connectivity(b,n) == 2){
		printf("This is an unconnected graphs.\n");//这不是联通有向图 
	}
	
	return 0;
}
