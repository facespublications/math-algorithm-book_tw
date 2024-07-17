#include <iostream>
using namespace std;

long long L, R; bool prime[500009];

int main() {
	// 輸入
	cin >> L >> R;

	// 陣列的初始化
	for (long long i = 0; i <= R - L; i++) {
		prime[i] = true;
	}

	// 區分出 L = 1 時的狀況（邊角案例）
	if (L == 1) prime[0] = false;

	// 篩選
	for (long long i = 2; i * i <= R; i++) {
		long long min_value = ((L + i - 1) / i) * i; // 在 L 以上之最小的 i 的倍數
		// 將 L 以上 R 以下的所有（除 i 以外的）i 的倍數標記為×
		for (long long j = min_value; j <= R; j += i) {
			if (j == i) continue;
			prime[j - L] = false;
		}
	}

	// 計數個數並輸出
	long long answer = 0;
	for (long long i = 0; i <= R - L; i++) {
		if (prime[i] == true) answer += 1;
	}
	cout << answer << endl;
	return 0;
}