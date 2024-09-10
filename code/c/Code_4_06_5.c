#include <stdio.h>

long long modpow(long long a, long long b, long long m) {
	// 重複平方法（p 取 a^1、a^2、 a^4、a^8、⋯的值）
	long long p = a, answer = 1;
	int i;
	for (i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) {
			answer = (answer * p) % m;
		}
		p = (p * p) % m;
	}
	return answer;
}

// Division(a, b, m) 是回傳a÷b mod m 的函式
long long division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

int main() {
	// 輸入
	int X, Y;
	scanf("%d%d", &X, &Y);
	
	// 求出二項係數的分子和分母（步驟1./ 步驟2.）
	const long long MOD = 1000000007;
	long long bunshi = 1, bunbo = 1;
	int i;
	for (i = 1; i <= X + Y; i++) {
		bunshi = (bunshi * i) % MOD;
	}
	for (i = 1; i <= X; i++) {
		bunbo = (bunbo * i) % MOD;
	}
	for (i = 1; i <= Y; i++) {
		bunbo = (bunbo * i) % MOD;
	}
	
	// 求出答案（步驟3.）
	printf("%lld\n", division(bunshi, bunbo, MOD));
	
	return 0;
}
