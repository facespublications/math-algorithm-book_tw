#include <stdio.h>

int main() {
	// 輸入
	int N; long long X, Y;
	scanf("%d%lld%lld", &N, &X, &Y);

	// 4 個整數(a, b, c, d) 的全搜尋→輸出答案
	int a, b, c, d;
	for (a = 1; a <= N; a++) {
		for (b = a; b <= N; b++) {
			for (c = b; c <= N; c++) {
				for (d = c; d <= N; d++) {
					if (a + b + c + d == X && 1LL * a * b * c * d == Y) {
						printf("Yes\n");
						return 0; // 使程式結束執行
					}
				}
			}
		}
	}
	printf("No\n"); // 如果連 1 組都沒發現的話為No
	return 0;
}
