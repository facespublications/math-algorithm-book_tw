#include <stdio.h>

int main() {
	// 輸入
	int N, X;
	scanf("%d%d", &N, &X);

	// 嘗試所有 (a, b, c) 的組合
	int answer = 0;
	int a, b, c;
	for (a = 1; a <= N; a++) {
		for (b = a + 1; b <= N; b++) {
			for (c = b + 1; c <= N; c++) {
				if (a + b + c == X) {
					answer += 1;
				}
			}
		}
	}

	// 輸出答案
	printf("%d\n", answer);

	return 0;
}