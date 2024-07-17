#include <stdio.h>
#include <math.h>

int N;
double x[2009], y[2009];
double Answer = 1000000000.0; // 初始化成非常大的值

int main() {
	// 輸入
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%lf%lf", &x[i], &y[i]);
	
	// 全搜尋
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			// dist 為第 i 個點與第 j 個點之間的距離
			double dist = sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]));
			if (Answer > dist) {
				Answer = dist;
			}
		}
	}
	
	// 輸出答案
	printf("%.12lf\n", Answer);
	return 0;
}