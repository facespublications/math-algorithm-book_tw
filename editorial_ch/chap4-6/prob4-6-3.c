#include <stdio.h>
 
const long long mod = 1000000007;
long long N;
 
long long modpow(long long a, long long b, long long m) {
	// 重複平方法（p 取如 a^1, a^2, a^4, a^8, ... 的值）
	long long p = a, Answer = 1;
	for (int i = 0; i < 60; i++) {
		if ((b & (1LL << i)) != 0) { Answer *= p; Answer %= m; }
		p *= p; p %= m;
	}
	return Answer;
}
 
// Division(a, b, m) 為傳回 a÷b mod m 的函式
long long Division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}
 
int main() {
	// 輸入
	scanf("%d", &N);
	
	// 計算答案
	long long V = modpow(4, N + 1, mod) - 1;
	long long Answer = Division(V, 3, mod);
	
	// 輸出
	printf("%lld\n", Answer);
	return 0;
}