#include <stdio.h>
#include <stdbool.h>
 
// K=2 時的轉移
long long Mat2[4][4] = {
	{0, 0, 0, 1},
	{0, 0, 1, 0},
	{0, 1, 0, 0},
	{1, 0, 0, 1}
};
 
// K=3 時的轉移
long long Mat3[8][8] = {
	{0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 1, 0}
};
 
// K=4 時的轉移
long long Mat4[16][16] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
	{1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1}
};
 
struct Matrix {
	int size_; // 矩陣的大小（設為 size_ × size_ 的正方矩陣）
	long long p[16][16];
};

struct Matrix Multiplication(struct Matrix A, struct Matrix B) { // 回傳矩陣 A, B 乘積的函式
	struct Matrix C;
 
	// 矩陣 C 的初始化
	C.size_ = A.size_;
	for (int i = 0; i < A.size_; i++) {
		for (int j = 0; j < A.size_; j++) C.p[i][j] = 0;
	}
 
	// 矩陣的乘法
	for (int i = 0; i < A.size_; i++) {
		for (int k = 0; k < A.size_; k++) {
			for (int j = 0; j < A.size_; j++) {
				C.p[i][j] += A.p[i][k] * B.p[k][j];
				C.p[i][j] %= 1000000007;
			}
		}
	}
	return C;
}
 
struct Matrix Power(struct Matrix A, long long n) { // 回傳 A 的 n 次方的函式
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
	// 輸入
	long long K, N;
	scanf("%lld%lld", &K, &N);
 
	// 製作矩陣 A
	struct Matrix A; A.size_ = (1 << K);
	for (int i = 0; i < (1 << K); i++) {
		for (int j = 0; j < (1 << K); j++) {
			if (K == 2) A.p[i][j] = Mat2[i][j];
			if (K == 3) A.p[i][j] = Mat3[i][j];
			if (K == 4) A.p[i][j] = Mat4[i][j];
		}
	}
 
	// B=A^N 的計算
	struct Matrix B = Power(A, N);
 
	// 輸出答案
	printf("%lld\n", B.p[(1 << K) - 1][(1 << K) - 1]);
	return 0;
}