#include <stdio.h>

const long long mod = 1000000007;
int X, Y;

long long modpow(long long a, long long b, long long m) {
	// 重複平方法（p 取如 a^1, a^2, a^4, a^8, ... 的值）
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
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
	scanf("%d%d", &X, &Y);
	
	// 狀況區分（a, b 會變成負的時候）
	if (2 * Y - X < 0 || 2 * X - Y < 0) {
		printf("0\n");
		return 0;
	}
	
	// 狀況區分（a, b 不會成為整數的時候）
	if ((2 * Y - X) % 3 != 0 || (2 * X - Y) % 3 != 0) {
		printf("0\n");
		return 0;
	}
	
	// 求出二項係數的分子與分母（步驟 1.／步驟 2.）
	long long bunshi = 1, bunbo = 1;
	long long a = (2 * Y - X) / 3, b = (2 * X - Y) / 3;
	for (int i = 1; i <= a + b; i++) { bunshi *= i; bunshi %= mod; }
	for (int i = 1; i <= a; i++) { bunbo *= i; bunbo %= mod; }
	for (int i = 1; i <= b; i++) { bunbo *= i; bunbo %= mod; }
	
	// 求出答案（步驟 3.）
	printf("%lld\n", Division(bunshi, bunbo, mod));
	return 0;
}