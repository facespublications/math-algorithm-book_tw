#include <stdio.h>

int N;
double A[109], B[109];
double Answer = 0.0;

int main() {
	// 輸入
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%lf", &A[i]);
	for (int i = 1; i <= N; i++) scanf("%lf", &B[i]);
	
	// 求出期望值
	for (int i = 1; i <= N; i++) {
		double eval = A[i] * (1.0 / 3.0) + B[i] * (2.0 / 3.0);
		Answer += eval;
	}
	
	// 輸出
	printf("%.12lf\n", Answer);
	return 0;
}