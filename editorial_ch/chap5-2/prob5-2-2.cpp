#include <iostream>
using namespace std;
 
int main() {
	// 輸入
	long long N;
	cin >> N;
	
	// 檢查是否以 N = 2^k-1 的形式表示
	bool flag = false;
	for (int k = 1; k <= 60; k++) {
		if (N == (1LL << k) - 1LL) flag = true;
	}
	
	// 輸出
	if (flag == true) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}