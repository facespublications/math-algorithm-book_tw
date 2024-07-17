#include <stdio.h>

int N, A[109];
int Answer = 0;

int main() {
	// 輸入
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	// 計算答案
	for (int i = 1; i <= N; i++) {
		Answer += A[i];
	}

	// 輸出
	printf("%d\n", Answer % 100);
	return 0;
}
