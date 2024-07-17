#include <iostream>
#include <algorithm>
using namespace std;

// 傳回最大公因數的函式
long long GCD(long long A, long long B) {
	while (A >= 1 && B >= 1) {
		if (A < B) B = B % A; // A < B 時，改寫較大的數 B
		else A = A % B; // A >= B 時，改寫較大的數 A
	}
	if (A >= 1) return A;
	return B;
}

// 傳回最小公倍數的函式
long long LCM(long long A, long long B) {
	return (A / GCD(A, B)) * B;
}

long long N;
long long A[100009];

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 求出答案
	long long R = LCM(A[1], A[2]);
	for (int i = 3; i <= N; i++) {
		R = LCM(R, A[i]);
	}
	
	// 輸出
	cout << R << endl;
	return 0;
}