#include <iostream>
using namespace std;

const long long mod = 1000000007;
int X, Y;

long long modpow(long long a, long long b, long long m) {
	// 重複平方法（p 取 a^1、a^2、 a^4、a^8、⋯的值）
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
		p *= p; p %= m;
	}
	return Answer;
}

// Division(a, b, m) 是回傳　a÷b mod m 的函式関
long long Division(long long a, long long b, long long m) {
	return (a * modpow(b, m - 2, m)) % m;
}

int main() {
	// 輸入
	cin >> X >> Y;

	// 求出二項係數的分子和分母（步驟1./ 步驟2.）
	long long bunshi = 1, bunbo = 1;
	for (int i = 1; i <= X + Y; i++) { bunshi *= i; bunshi %= mod; }
	for (int i = 1; i <= X; i++) { bunbo *= i; bunbo %= mod; }
	for (int i = 1; i <= Y; i++) { bunbo *= i; bunbo %= mod; }

	// 求出答案（步驟3.）
	cout << Division(bunshi, bunbo, mod) << endl;
	return 0;
}
