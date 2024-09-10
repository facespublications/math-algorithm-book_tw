#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b; // 輸入 a 及 b
	cout << (a & b) << endl; // 輸出 a AND b的值
	cout << (a | b) << endl; // 輸出 a OR b的值
	cout << (a ^ b) << endl; // 輸出 a XOR b的值
	return 0;
}
