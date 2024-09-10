#include <stdio.h>

int N; long long A[200009];

int main() {
	// 輸入
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	// 求解 → 輸出答案
	long long answer = 0;
	for (i = 1; i <= N; i++) {
		answer += A[i] * (-N + 2LL * i - 1LL);
	}
	printf("%lld\n", answer);
	return 0;
}
