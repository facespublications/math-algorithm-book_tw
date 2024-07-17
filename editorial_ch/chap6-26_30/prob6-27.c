#include <stdio.h>

long long modpow(long long a, long long b, long long m) {
	// 重複平方法（p 取 a^1, a^2, a^4, a^8, ... 等值）
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

// division(a, b, m) 是回傳 a÷b mod m 的函式
long long division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

const long long MOD = 1000000007;
long long fact[200009];

long long ncr(int n, int r) {
	// ncr 是將 n! 除以 r! × (n-r)! 的值
	return division(fact[n], fact[r] * fact[n - r] % MOD, MOD);
}

int main() {
	// 陣列的初始化（fact[i] 為將 i 的階乘除以 1000000007 的餘數）
	fact[0] = 1;
	int i;
	for (i = 1; i <= 200000; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	// 輸入 → 計算答案並輸出
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int answer = 0;
		for (int j = 1; i * (j - 1) < N; j++) {
			answer += ncr(N - (i - 1) * (j - 1), j);
			answer %= MOD;
		}
		printf("%d\n", answer);
	}
	
	return 0;
}