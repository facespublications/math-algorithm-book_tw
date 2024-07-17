#include <iostream>
using namespace std;

int N, A[109];
int Answer = 0;

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	// 計算答案
	for (int i = 1; i <= N; i++) {
		Answer += A[i];
	}

	// 輸出
	cout << Answer % 100 << endl;
	return 0;
}
