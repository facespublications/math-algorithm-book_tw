#include <stdio.h>
 
const long long mod = 998244353;
long long A, B, C;
 
int main() {
	// 輸入
	scanf("%lld%lld%lld", &A, &B, &C);
	
	// 計算
	long long D = A * (A + 1) / 2; D %= mod;
	long long E = B * (B + 1) / 2; E %= mod;
	long long F = C * (C + 1) / 2; F %= mod;
	
	// 輸出答案
	// 即使在此計算 (D * E * F) % mod ，可能在途中處理到 10^27 
	// 因此，注意即使是 long long 型態也會發生溢出！
	printf("%lld\n", (D * E % mod) * F % mod);
	return 0;
}