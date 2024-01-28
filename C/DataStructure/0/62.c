#include<stdio.h>
int main(){
    int num_1, num_2;
    scanf("%d %d", &num_1, &num_2);
    int sum, del, pro, quo, mod;
    sum = num_1 + num_2;
    del = num_1 - num_2;
    pro = num_1 * num_2;
    quo = num_1 / num_2;
    mod = num_1 % num_2;
    printf("%d %d %d %d %d", sum, del, pro, quo, mod);
    return 0;
}