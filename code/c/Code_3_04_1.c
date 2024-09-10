#include <stdio.h>

int N, B[100009], R[100009];

int main() {
	// 輸入
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
	}
	for (i = 1; i <= N; i++) {
		scanf("%d", &R[i]);
	}

	// 答案的計算 → 答案的輸出
	double blue = 0.0, red = 0.0;
	for (i = 1; i <= N; i++) {
		blue += 1.0 * B[i] / N;
		red += 1.0 * R[i] / N;
	}
	printf("%.12lf\n", blue + red);
	return 0;
}
