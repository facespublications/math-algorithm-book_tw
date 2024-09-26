#include <iostream>
using namespace std;
 
const long long mod = 1000000007;
long long N;
 
int main() {
	// 輸入
	cin >> N;
	
	// 求出答案
	long long val = N * (N + 1) / 2;
	val %= mod;
	cout << val * val % mod << endl;
	return 0;
}