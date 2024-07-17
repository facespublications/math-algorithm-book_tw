#include <stdio.h>
#include <stdbool.h>

typedef struct {
	double x[3][3];
} matrix;

// 回傳 3×3 的 0 矩陣 (= [[0, 0, 0], [0, 0, 0], [0, 0, 0]])
matrix zero_matrix() {
	matrix A;
	A.x[0][0] = 0; A.x[0][1] = 0; A.x[0][2] = 0;
	A.x[1][0] = 0; A.x[1][1] = 0; A.x[1][2] = 0;
	A.x[2][0] = 0; A.x[2][1] = 0; A.x[2][2] = 0;
	return A;
}

// 回傳 3×3 矩陣乘積的函式
matrix multiplication(matrix A, matrix B) {
	matrix C = zero_matrix();
	int i, j, k;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				C.x[i][j] += A.x[i][k] * B.x[k][j];
			}
		}
	}
	return C;
}

// 回傳矩陣 A 的 n 次方的函式
matrix power(matrix A, int n) {
	matrix P = A;
	matrix Q = zero_matrix();
	bool flag = false;
	for (int i = 0; i < 30; i++) {
		if ((n & (1 << i)) != 0LL) {
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
	int Q, T; double X, Y, Z;
	scanf("%d", &Q);
	for (int t = 1; t <= Q; t++) {
		// 輸入 → 建構矩陣 A
		scanf("%lf%lf%lf%d", &X, &Y, &Z, &T);
		matrix A = zero_matrix();
		A.x[0][0] = 1.0 - X; A.x[2][0] = X;
		A.x[1][1] = 1.0 - Y; A.x[0][1] = Y;
		A.x[2][2] = 1.0 - Z; A.x[1][2] = Z;
 
		// 矩陣乘方的計算 → 輸出答案
		matrix B = power(A, T);
		double answerA = B.x[0][0] + B.x[0][1] + B.x[0][2];
		double answerB = B.x[1][0] + B.x[1][1] + B.x[1][2];
		double answerC = B.x[2][0] + B.x[2][1] + B.x[2][2];
		printf("%.12lf %.12lf %.12lf\n", answerA, answerB, answerC);
	}
	return 0;
}