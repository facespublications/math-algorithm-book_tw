#include <stdio.h>

long long N;
long long F[10000009];
long long Answer = 0;

int main() {
	// 輸入 → 陣列的初始化
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) F[i] = 0;
	
	// 計算 F[1], F[2], ..., F[N]
	for (int i = 1; i <= N; i++) {
		// 對 F[i], F[2i], F[3i], ... 加算 1
		for (int j = i; j <= N; j += i) F[j] += 1;
	}
	
	// 求出答案 → 輸出
	for (int i = 1; i <= N; i++) {
		Answer += 1LL * i * F[i];
	}
	printf("%lld\n", Answer);
	return 0;
}