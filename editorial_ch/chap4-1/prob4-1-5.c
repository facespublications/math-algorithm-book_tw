#include <stdio.h>
#include <stdbool.h>

void swap(long long *x, long long *y) {
    long long tmp = *x;
    *x = *y;
    *y = tmp;
}

long long max(long long p1, long long p2) {
	if (p1 < p2) return p2;
	return p1;
}

long long min(long long p1, long long p2) {
	if (p1 < p2) return p1;
	return p2;
}

long long cross(long long ax, long long ay, long long bx, long long by) {
	// 向量 (ax, ay) 與 (bx, by) 的外積大小
	return ax * by - ay * bx;
}

int main() {
	// 輸入
	long long X1, Y1, X2, Y2, X3, Y3, X4, Y4;
	scanf("%lld%lld", &X1, &Y1); // 輸入點 A 的座標
	scanf("%lld%lld", &X2, &Y2); // 輸入點 B 的座標
	scanf("%lld%lld", &X3, &Y3); // 輸入點 C 的座標
	scanf("%lld%lld", &X4, &Y4); // 輸入點 D 的座標
	
	// 計算 cross(AB, AC)
	long long ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
	long long ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
	long long ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
	long long ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);
	
	// 全部排在一直線上時（邊角案例）
	// 因為無法使用　pair 型態，與　C++ 的實作方法會稍有差異
	if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
		if (X1 == X2 && X2 == X3 && X3 == X4) {
			long long a = Y1, b = Y2; if (a > b) swap(&a, &b);
			long long c = Y3, d = Y4; if (c > d) swap(&c, &d);
			if (max(a, c) <= min(b, d)) printf("Yes\n");
			else printf("No\n");
		}
		else {
			long long a = X1, b = X2; if (a > b) swap(&a, &b);
			long long c = X3, d = X4; if (c > d) swap(&c, &d);
			if (max(a, c) <= min(b, d)) printf("Yes\n");
			else printf("No\n");
		}
		return 0;
	}
	
	// 並非如此時
	// IsAB: 線段 AB 是否將點 C, D 分開？
	// IsCD: 線段 CD 是否將點 A, B 分開？
	bool IsAB = false, IsCD = false;
	if (ans1 >= 0 && ans2 <= 0) IsAB = true;
	if (ans1 <= 0 && ans2 >= 0) IsAB = true;
	if (ans3 >= 0 && ans4 <= 0) IsCD = true;
	if (ans3 <= 0 && ans4 >= 0) IsCD = true;
	
	// 輸出答案
	if (IsAB == true && IsCD == true) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}