#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	// 輸入
	long long ax, ay, bx, by, cx, cy;
	scanf("%lld%lld%lld%lld%lld%lld", &ax, &ay, &bx, &by, &cx, &cy);

	// 求向量BA、BC、CA、CB 的分量表示
	long long BAx = (ax - bx), BAy = (ay - by);
	long long BCx = (cx - bx), BCy = (cy - by);
	long long CAx = (ax - cx), CAy = (ay - cy);
	long long CBx = (bx - cx), CBy = (by - cy);

	// 判斷適用哪一個模式
	int pattern = 2;
	if (BAx * BCx + BAy * BCy < 0LL) pattern = 1;
	if (CAx * CBx + CAy * CBy < 0LL) pattern = 3;

	// 求出點與直線的距離
	double answer = 0.0;
	if (pattern == 1) answer = sqrt(BAx * BAx + BAy * BAy);
	if (pattern == 3) answer = sqrt(CAx * CAx + CAy * CAy);
	if (pattern == 2) {
		double S = llabs(BAx * BCy - BAy * BCx);
		double BCLength = sqrt(BCx * BCx + BCy * BCy);
		answer = S / BCLength;
	}

	// 輸出答案
	printf("%.12lf\n", answer);
	return 0;
}
