#include <iostream>
using namespace std;

bool isprime(int x) {
	for (int i = 2; i <= x - 1; i++) {
		// 將 x 除以 i 的餘數為 0 時、x 可以被 i 整除
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	// 輸入
	int N;
	cin >> N;
	
	// 輸出答案（以空白來區隔輸出）
	for (int i = 2; i <= N; i++) {
		if (isprime(i) == true) {
			if (i >= 3) cout << " ";
			cout << i;
		}
	}
	cout << endl;
	return 0;
}