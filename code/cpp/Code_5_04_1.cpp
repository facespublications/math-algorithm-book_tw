#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	// 輸入
	int N, K;
	cin >> N >> K;

	// 算出事件 B 的個數 yojishou → 輸出答案
	long long yojishou = 0;
	for (int a = 1; a <= N; a++) {
		for (int b = max(1, a - (K - 1)); b <= min(N, a + (K - 1)); b++) {
			for (int c = max(1, a - (K - 1)); c <= min(N, a + (K - 1)); c++) {
				if (abs(b - c) <= K - 1) yojishou += 1;
			}
		}
	}
	cout << (long long)N * N * N - yojishou << endl;
	return 0;
}
