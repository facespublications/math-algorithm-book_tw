#include <stdio.h>

int N, dp[54];

int main() {
	// 輸入
	scanf("%d", &N);

	// 動態規劃法 → 輸出答案
	int i;
	for (i = 0; i <= N; i++) {
		if (i <= 1) dp[i] = 1;
		else dp[i] = dp[i - 1] + dp[i - 2];
	}
	printf("%d\n", dp[N]);
	return 0;
}
