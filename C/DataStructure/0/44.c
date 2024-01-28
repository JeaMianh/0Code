#include <stdio.h>
#include <math.h>

// 判断一个数是否是素数，是则返回1，否则返回0
int is_prime(int n) {
  if (n < 2) return 0; // 0和1不是素数
  if (n == 2) return 1; // 2是素数
  if (n % 2 == 0) return 0; // 偶数不是素数
  // 从3开始，每次加2，只需判断到sqrt(n)即可
  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) return 0; // 如果有其他因数，不是素数
  }
  return 1; // 没有其他因数，是素数
}

// 计算斐波纳契数列中的第n个数字，n从1开始计数
int fibonacci(int n) {
  if (n <= 2) return 1; // 前两个数字都是1
  int a = 1, b = 1, c; // a和b分别表示前两个数字，c表示当前数字
  for (int i = 3; i <= n; i++) {
    c = a + b; // 当前数字等于前两个数字之和
    a = b; // 更新a为前一个数字
    b = c; // 更新b为当前数字
  }
  return c; // 返回第n个数字
}

int main() {
  int n; // 输入的数字

  scanf("%d", &n); // 读取输入的数字
  
  int f = fibonacci(n); // 计算斐波纳契数列中的第n个数字
  
  if (is_prime(f)) {
    printf("yes"); // 如果是素数，输出结果
  } else {
    printf("%d", f); // 如果不是素数，输出结果
  }
  return 0; // 程序正常结束
}
