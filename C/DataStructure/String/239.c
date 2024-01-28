//
// Created by GT on 2022/11/29.
//
 
#include<stdio.h>
int main()
{
    int a[110][110]={0};
    int i,j;
    int n;
    scanf("%d",&n);
 
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(j==0||j==i){
                a[i][j]=1;
            }else{
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}