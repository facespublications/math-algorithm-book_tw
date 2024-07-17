#include <stdio.h>

long long N, A[200009];
long long cnt[100009];
long long Answer = 0;

int main() {
	// 輸入
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	
	// 計數 cnt[1], cnt[2], ..., cnt[99999]
	for (int i = 1; i <= 99999; i++) cnt[i] = 0;
	for (int i = 1; i <= N; i++) cnt[A[i]] += 1;
	
	// 求出答案
	for (int i = 1; i <= 49999; i++) {
		Answer += cnt[i] * cnt[100000 - i];
	}
	Answer += cnt[50000] * (cnt[50000] - 1) / 2;
	
	// 輸出
	printf("%lld\n", Answer);
	return 0;
}