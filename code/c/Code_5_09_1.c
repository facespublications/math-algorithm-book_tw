#include <stdio.h>

int main() {
	// 輸入
	long long N;
	scanf("%lld", &N);

	// 支付方式的模擬
	long long answer = 0;
	while (N >= 10000) {
		N -= 10000;
		answer += 1;
	}
	while (N >= 5000) {
		N -= 5000;
		answer += 1;
	}
	while (N >= 1) {
		N -= 1000;
		answer += 1;
	}
	
	// 輸出答案
	printf("%lld\n", answer);
	return 0;
}
