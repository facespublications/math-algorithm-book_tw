#include <stdio.h>
 
const long long mod = 1000000007;
long long N;
 
int main() {
	// 輸入
	scanf("%lld", &N);
	
	// 求出答案
	long long val = N * (N + 1) / 2;
	val %= mod;
	printf("%lld\n", val * val % mod);
	return 0;
}