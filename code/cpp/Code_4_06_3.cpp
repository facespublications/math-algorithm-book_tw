#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long a, b, Answer = 1; // a　的 0 次方為 1，因此初始化成 Answer=1

int main() {
	cin >> a >> b;
	for (int i = 1; i <= b; i++) {
		Answer = (Answer * a) % mod;
	}
	cout << Answer << endl;
	return 0;
}
