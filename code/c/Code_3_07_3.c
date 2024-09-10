#include <stdio.h>

int N; long long W, w[109], v[109];
long long dp[109][100009];

int main() {
	// 輸入
	scanf("%d%lld", &N, &W);
	int i, j;
	for (i = 1; i <= N; i++) {
		scanf("%lld%lld", &w[i], &v[i]);
	}

	// 陣列的初始化
	dp[0][0] = 0;
	for (i = 1; i <= W; i++) {
		dp[0][i] = -(1LL << 60);
	}

	// 動態規劃法
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= W; j++) {
			// j<w[i] 時，無法用方法B 的選擇方法
			if (j < w[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			// j > = w[i-1] 時，可以選擇方法 A、方法 B 的任一個
			if (j >= w[i]) {
				long long v1 = dp[i - 1][j];
				long long v2 = dp[i - 1][j - w[i]] + v[i];
				dp[i][j] = (v1 > v2 ? v1 : v2); // v1 與 v2 之間較大的那個值
			}
		}
	}

	// 輸出答案
	long long answer = 0;
	for (i = 0; i <= W; i++) {
		answer = (answer > dp[N][i] ? answer : dp[N][i]);
	}
	printf("%lld\n", answer);
	return 0;
}
