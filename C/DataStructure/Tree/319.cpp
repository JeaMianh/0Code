#include <iostream>
#include <vector>
 
using namespace std;
vector<int> c;
 
void merge(vector<int> a, vector<int> b) {
	if (b.size() == 0) {
		return;
	}//如果子树的长度为0则返回
 
	vector<int> b1;
	vector<int> b2;
	//定义左右子树
	int root = a[0];//根节点是a的第一个元素
	int pos = 0, sum = 0;
 
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == root) {
			pos = i;
			break;
		}
	}//寻找子树中根节点的位置
 
	for (int i = 0; i < pos; i++) {
		b1.push_back(b[i]);
		sum += b[i];
	}//将子树分为更小的左右子树
 
	for (int i = pos + 1; i < b.size(); i++) {
		b2.push_back(b[i]);
		sum += b[i];
	}//将子树分为更小的左右子树
	
	merge(vector<int>(a.begin() + 1, a.begin() + 1 + b1.size()), b1);//a.begin() + 1, a.begin() + 1 + b1.size()此代码的意思为新的容器取a左子树
	c.push_back(sum);
	merge(vector<int>(a.begin() + 1 + b1.size(), a.end()), b2);//a.begin() + 1 + b1.size(), a.end()此代码的意思为取a右子树
}
 
int main() {
	int num;
	vector<int> a;
	vector<int> b;
 
	cin >> num;
	for (int i = 0; i < num; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < num; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	merge(a, b);
 
	for (int i = 0; i < c.size(); i++) {
		cout << c[i] << " ";
	}
	return 0;
}