#include <stdio.h>
 
int main() {
	// 輸入
	long long N;
	scanf("%lld", &N);
	
	// 輸出
	printf("%lld\n", N * (N - 1) / 2);
	return 0;
}