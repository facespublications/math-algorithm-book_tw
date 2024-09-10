#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 10000; // N為測試次數（可適當變更）
	int M = 0;
	int i;
	for (i = 1; i <= N; i++) {
		double px = rand() / (double)RAND_MAX; // 生成 0 以上1 以下的亂數（隨機的數）
		double py = rand() / (double)RAND_MAX; // 生成 0 以上1 以下的亂數（隨機的數）
		// 與原點的距離為sqrt(px * px + py * py)
		// 此值最好在1 以下，因此條件為「px * px + py * py <= 1」
		if (px * px + py * py <= 1.0) M += 1;
	}
	printf("%.12lf\n", 4.0 * M / N);
	return 0;
}
