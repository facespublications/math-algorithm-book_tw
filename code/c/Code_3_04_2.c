#include <stdio.h>

int main() {
	// 輸入
	int N, P[59], Q[59];
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d%d", &P[i], &Q[i]);
	}

	// 答案的計算 → 答案的輸出
	double answer = 0.0;
	for (i = 1; i <= N; i++) {
		answer += 1.0 * Q[i] / P[i];
	}
	printf("%.12lf\n", answer);
	return 0;
}
