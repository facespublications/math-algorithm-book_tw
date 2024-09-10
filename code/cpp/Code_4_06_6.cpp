#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long X, Y;
long long fact[200009];

long long modpow(long long a, long long b, long long m) {
	// 重複平方法（p 取 a^1、a^2、 a^4、a^8、⋯的值）
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
		p *= p; p %= m;
	}
	return Answer;
}

long long Division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

long long ncr(int n, int r) {
	// ncr 是n! 除以r!×(n-r)! 的值
	return Division(fact[n], fact[r] * fact[n - r] % mod, mod);
}

int main() {
	// 陣列初始化（fact[i] 是i 的階乘除以10000007 的餘數）
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++) fact[i] = 1LL * i * fact[i - 1] % mod;

	// 輸入→答案輸出
	cin >> X >> Y;
	cout << ncr(X + Y, Y) << endl;
	return 0;
}
