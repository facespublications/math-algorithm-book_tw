#include <iostream>
#include <algorithm>
using namespace std;

long long N, W, w[109], v[109];
long long dp[109][100009];

int main() {
	// 輸入
	cin >> N >> W;
	for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

	// 陣列的初始化
	dp[0][0] = 0;
	for (int i = 1; i <= W; i++) dp[0][i] = -(1LL << 60);

	// 動態規劃法
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= W; j++) {
			// j<w[i] 時，無法用方法B 的選擇方法
			if (j < w[i]) dp[i][j] = dp[i - 1][j];
			// j > = w[i-1] 時，可以選擇方法 A、方法 B 的任一個
			if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	// 輸出答案
	long long Answer = 0;
	for (int i = 0; i <= W; i++) Answer = max(Answer, dp[N][i]);
	cout << Answer << endl;
	return 0;
}
