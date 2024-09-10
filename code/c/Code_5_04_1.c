#include <stdio.h>
#include <stdlib.h>

int minimum(int a, int b) {
	return (a < b ? a : b);
}

int maximum(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	// 輸入
	int N, K;
	scanf("%d%d", &N, &K);

	// 算出事件 B 的個數 yojishou → 輸出答案
	long long yojishou = 0;
	int a, b, c;
	for (a = 1; a <= N; a++) {
		int l = maximum(a - (K - 1), 1); // b, c 的探索範圍下限 l
		int r = minimum(a + (K - 1), N); // b, c 的探索範圍上限 r
		for (b = l; b <= r; b++) {
			for (c = l; c <= r; c++) {
				if (abs(b - c) <= K - 1) yojishou += 1;
			}
		}
	}
	
	// 輸出答案
	printf("%lld\n", (long long)N * N * N - yojishou);
	return 0;
}
