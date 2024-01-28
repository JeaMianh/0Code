#include<stdio.h>
int main() {
    int num, res;
    scanf("%d", &num);
    if(num < 1) {
        res = num;
    } else if(num < 10) {
        res = 2 * num - 1;
    } else {
        res = 3 * num - 11;
    }
    printf("%d", res);
    return 0;
}