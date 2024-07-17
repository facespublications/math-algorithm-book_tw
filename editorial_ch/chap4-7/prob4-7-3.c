#include <stdio.h>
#include <stdbool.h>

struct Matrix {
	long long p[3][3];
};

// 回傳 3×3 矩陣 A, B 乘積的函式
struct Matrix Multiplication(struct Matrix A, struct Matrix B) { 
	struct Matrix C;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) C.p[i][j] = 0;
	}
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				C.p[i][j] += A.p[i][k] * B.p[k][j];
				C.p[i][j] %= 1000000007;
			}
		}
	}
	return C;
}

// 回傳 A 的 n 次方的函式
struct Matrix Power(struct Matrix A, long long n) { 
	struct Matrix P = A, Q;
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
	scanf("%lld", &N);
	
	// 製作矩陣 A
	struct Matrix A;
	A.p[0][0] = 1; A.p[0][1] = 1; A.p[0][2] = 1;
	A.p[1][0] = 1; A.p[1][1] = 0; A.p[1][2] = 0;
	A.p[2][0] = 0; A.p[2][1] = 1; A.p[2][2] = 0;
	
	// B=A^{N-1} 的計算
	struct Matrix B = Power(A, N - 1);

	// 輸出答案
	printf("%lld\n", ((long long)2 * B.p[2][0] + B.p[2][1] + B.p[2][2]) % 1000000007);
	return 0;
}