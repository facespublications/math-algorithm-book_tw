#include <stdio.h>
#include <stdbool.h>

const long long MOD = 1000000000;

typedef struct {
	long long p[2][2];
} matrix;

// 回傳 2×2 的空矩陣 (= [[0, 0], [0, 0]]) 
matrix zero_matrix() {
	matrix A;
	A.p[0][0] = 0; A.p[0][1] = 0;
	A.p[1][0] = 0; A.p[1][1] = 0;
	return A;
}

// 回傳2×2 矩陣 A、B 乘積的函式
matrix multiplication(matrix A, matrix B) {
	matrix C = zero_matrix();
	int i, j, k;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 2; k++) {
				C.p[i][j] += A.p[i][k] * B.p[k][j];
				C.p[i][j] %= MOD;
			}
		}
	}
	return C;
}

// 回傳 A 的 n 次方的函式
matrix power(matrix A, long long n) {
	matrix P = A;
	matrix Q = zero_matrix();
	bool flag = false;
	for (int i = 0; i < 60; i++) {
		if ((n & (1LL << i)) != 0LL) {
			if (flag == false) {
				Q = P;
				flag = true;
			}
			else {
				Q = multiplication(Q, P);
			}
		}
		P = multiplication(P, P);
	}
	return Q;
}

int main() {
	// 輸入→乘方的計算（請注意，N 必須大於 2 才能正常運作）
	long long N;
	scanf("%lld", &N);
	matrix A; A.p[0][0] = 1; A.p[0][1] = 1; A.p[1][0] = 1; A.p[1][1] = 0;
	matrix B = power(A, N - 1);
	
	// 輸出（請注意，倒數第 9 位為 0 時，以開頭不含 0 的形式輸出）
	printf("%lld\n", (B.p[1][0] + B.p[1][1]) % MOD);
	
	return 0;
}
