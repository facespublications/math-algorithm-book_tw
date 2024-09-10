#include <iostream>
using namespace std;

int main() {
	// 輸入
	long long N, Answer = 0;
	cin >> N;

	// 支付方式的模擬 → 輸出答案
	while (N >= 10000) { N -= 10000; Answer += 1; }
	while (N >= 5000) { N -= 5000; Answer += 1; }
	while (N >= 1) { N -= 1000; Answer += 1; }
	cout << Answer << endl;
	return 0;
}
