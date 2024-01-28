#include<iostream>
#define MAXSIZE 100
using namespace std;
int count = 0;
void insert(int num[], int n) {
	if (n < 2) {
		return;
	}
	for (int i = 1; i < n; i++) {
		int key = num[i];
		//防止插入的数字最小~~
		bool flag = false;
		//倒序遍历
		for (int j = i - 1; j > -1; j--) {
			if (key < num[j]) {
				num[j + 1] = num[j]; //右移
			} else {
				num[j + 1] = key;
				flag = true;
				break;
			}
		}
		if (!flag) { //如果最小
			num[0] = key;
		}
		if (i > 0 && i < 4) {
			for (int i = 0; i < n; i++) {
				cout << num[i] << ' ';
			}
			cout << '\n';
		}
 
	}
}
int main() {
	int n;
	cin >> n;
	int num[MAXSIZE] = {0};
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	insert(num, n);
//	for (int i = 0; i < n; i++) {
//		cout << num[i] << ' ';
//	}
 
	return 0;
}