#include <iostream>
using namespace std;

int N, dp[54];

int main() {
	// 輸入
	cin >> N;

	// 動態規劃法 → 輸出答案
	for (int i = 0; i <= N; i++) {
		if (i <= 1) dp[i] = 1;
		else dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N] << endl;
	return 0;
}
