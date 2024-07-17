import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long K = sc.nextLong();
		long N = sc.nextLong();
		
		// 製作矩陣 A
		long[][] A = new long[(1 << K)][(1 << K)];
		for (int i = 0; i < (1 << K); i++) {
			for (int j = 0; j < (1 << K); j++) {
				if (K == 2) A[i][j] = Mat2[i][j];
				if (K == 3) A[i][j] = Mat3[i][j];
				if (K == 4) A[i][j] = Mat4[i][j];
			}
		}
		
		// 計算 B = A^N
		long[][] B = copyMatrix(power(A, N, (1 << K)), (1 << K));
		
		// 輸出答案
		System.out.println(B[(1 << K) - 1][(1 << K) - 1]);
	}
	static final int MOD = 1000000007;
	static final long[][] Mat2 = {
		{0, 0, 0, 1},
		{0, 0, 1, 0},
		{0, 1, 0, 0},
		{1, 0, 0, 1}
	};
	static final long[][] Mat3 = {
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 1, 0}
	};
	static final long[][] Mat4 = {
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
	static long[][] copyMatrix(long[][] A, int size_) {
		// 矩陣的複製（注意如果直接以「M = A;」來複製，則只會複製到參照）
		long[][] M = new long[size_][size_];
		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				M[i][j] = A[i][j];
			}
		}
		return M;
	}
	static long[][] multiplication(long[][] A, long[][] B, int size_) {
		// 回傳矩陣 A, B 乘積的函式
		long[][] C = new long[size_][size_];
		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				for (int k = 0; k < size_; k++) {
					C[i][j] += A[i][k] * B[k][j];
					C[i][j] %= MOD;
				}
			}
		}
		return C;
	}
	static long[][] power(long[][] A, long n, int size_) {
		// 回傳 A 的 n 次方的函式
		long[][] P = copyMatrix(A, size_);
		long[][] Q = new long[size_][size_];
		boolean flag = false;
		for (int i = 0; i < 60; i++) {
			if ((n & (1L << i)) != 0L) {
				if (flag == false) {
					Q = copyMatrix(P, size_);
					flag = true;
				}
				else {
					Q = copyMatrix(multiplication(Q, P, size_), size_);
				}
			}
			P = copyMatrix(multiplication(P, P, size_), size_);
		}
		return Q;
	}
}