#include <stdio.h>

int main() {
	// 輸入
	long long a, b, c, d;
	scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
	
	// 求解（answer 一開始設定為不可能的數值）
	long long answer = -(1LL << 62);
	if (answer < a * c) answer = a * c;
	if (answer < a * d) answer = a * d;
	if (answer < b * c) answer = b * c;
	if (answer < b * d) answer = b * d;
	
	// 輸出
	printf("%lld\n", answer);
	return 0;
}
