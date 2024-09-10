#include <stdio.h>
#include <stdlib.h>

int N, H[100009], dp[100009];

int main() {
	// 輸入
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &H[i]);
	}

	// 動態規劃法 → 輸出答案
	for (i = 1; i <= N; i++) {
		if (i == 1) dp[i] = 0;
		if (i == 2) dp[i] = abs(H[i - 1] - H[i]);
		if (i >= 3) {
			int v1 = dp[i - 1] + abs(H[i - 1] - H[i]); // 從前　1 個棚架起跳時
			int v2 = dp[i - 2] + abs(H[i - 2] - H[i]); // 從前　2 個棚架起跳時
			dp[i] = (v1 < v2 ? v1 : v2); // v1 與 v2 之間較小的那個值
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}
