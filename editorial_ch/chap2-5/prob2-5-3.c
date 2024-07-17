#include <stdio.h>

int main() {
	// 輸入
	int N;
	scanf("%d", &N);
	
	// 計算答案
	long long Answer = 1;
	for (int i = 2; i <= N; i++) Answer *= i;
	
	// 輸出
	printf("%lld\n", Answer);
	return 0;
}