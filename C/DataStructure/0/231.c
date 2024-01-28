
#include<stdio.h>
int main(){
    int number=0,max=0,i=0;
    char a[100];
    gets(a);
    for(i=0;a[i]!='\0';i++){
        number++;
        if(a[i]==' '||a[i]=='.'){
                number=0;
        }
        if(max<number){
            max=number;
        }
    }
    printf("%d",max);
}