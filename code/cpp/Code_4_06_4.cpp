#include <iostream>
using namespace std;

long long modpow(long long a, long long b, long long m) {
	// 重複平方法（p 取 a^1、a^2、 a^4、a^8、⋯的值）
	long long p = a, Answer = 1;
	for (int i = 0; i < 30; i++) {
		if ((b & (1 << i)) != 0) { Answer *= p; Answer %= m; }
		p *= p; p %= m;
	}
	return Answer;
}

const long long mod = 1000000007;
long long a, b;

int main() {
	cin >> a >> b;
	cout << modpow(a, b, mod) << endl;
	return 0;
}
