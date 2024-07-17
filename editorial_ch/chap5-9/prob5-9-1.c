#include <stdio.h>

int main() {
	// 輸入
	long long N, Answer = 0;
	scanf("%lld", &N);
	
	// 支付 10000 日圓鈔
	Answer += (N / 10000); N %= 10000;
	
	// 支付 5000 日圓鈔
	Answer += (N / 5000); N %= 5000;
	
	// 支付 1000 日圓鈔
	Answer += (N / 1000); N %= 1000;
	
	// 輸出答案
	printf("%lld\n", Answer);
	return 0;
}