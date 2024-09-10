#include <iostream>
using namespace std;

int cnt = 1000;

int func1() {
	return 2021;
}

int func2(int pos) {
	cnt += 1;
	return cnt + pos;
}

int main() {
	cout << func1() << endl; // 輸出「2021」
	cout << func2(500) << endl; // 輸出「1501」
	cout << func2(500) << endl; // 輸出「1502」
	return 0;
}
