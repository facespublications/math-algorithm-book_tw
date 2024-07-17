#include <iostream>
using namespace std;

struct Matrix {
	long long p[2][2] = { {0, 0}, {0, 0} };
};

Matrix Multiplication(Matrix A, Matrix B) { // 回傳 2×2 矩陣 A, B 乘積的函式
	Matrix C;
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < 2; j++) {
				C.p[i][j] += A.p[i][k] * B.p[k][j];
				C.p[i][j] %= 1000000007;
			}
		}
	}
	return C;
}

Matrix Power(Matrix A, long long n) { // 回傳 A 的 n 次方的函式
	Matrix P = A, Q;
	bool flag = false;
	for (int i = 0; i < 60; i++) {
		if ((n & (1LL << i)) != 0LL) {
			if (flag == false) { Q = P; flag = true; }
			else { Q = Multiplication(Q, P); }
		}
		P = Multiplication(P, P);
	}
	return Q;
}

int main() {
	// 輸入 → 乘方的計算（注意若 N 小於 2 的話不會正確動作）
	long long N;
	cin >> N;
	
	// 製作矩陣 A
	Matrix A;
	A.p[0][0] = 2; A.p[0][1] = 1; A.p[1][0] = 1;
	
	// B=A^{N-1} 的計算
	Matrix B = Power(A, N - 1);

	// 輸出答案
	cout << (B.p[1][0] + B.p[1][1]) % 1000000007 << endl;
	return 0;
}