#include <stdio.h>

int main() {
	// 輸入
	long long N;
	scanf("%lld", &N);

	// 將垂直長度從 1 到 √N 為止進行全搜尋
	long long answer = (1LL << 60);
	long long x;
	for (x = 1; x * x <= N; x++) {
		if (N % x == 0 && answer > 2 * x + 2 * (N / x)) {
			answer = 2 * x + 2 * (N / x);
		}
	}

	// 輸出答案
	printf("%lld\n", answer);

	return 0;
}