#include <iostream>
using namespace std;

const long long mod = 1000000007;
long long N;
long long A[300009];
long long power[300009];

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 求出 2^i
	power[0] = 1;
	for (int i = 1; i <= N; i++) {
		power[i] = (2 * power[i - 1]) % mod;
	}
	
	// 求出答案
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		Answer += power[i - 1] * A[i];
		Answer %= mod;
	}
	
	// 輸出
	cout << Answer << endl;
	return 0;
}