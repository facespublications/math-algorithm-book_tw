import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入 → 乘方的計算（注意若 N 小於 2 的話不會正確動作）
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long[][] A = new long[3][3];
		A[0][0] = 1; A[0][1] = 1; A[0][2] = 1;
		A[1][0] = 1; A[1][1] = 0; A[1][2] = 0;
		A[2][0] = 0; A[2][1] = 1; A[2][2] = 0;
		long[][] B = copyMatrix(power(A, N - 1));
		
		// 計算答案 → 輸出（注意如果從下往上數第 9 位是 0 ，以開頭不含 0 的形式輸出）
		long answer = (2 * B[2][0] + B[2][1] + B[2][2]) % MOD;
		System.out.println(answer);
	}
	static final int MOD = 1000000007;
	static long[][] copyMatrix(long[][] A) {
		// 矩陣のコピー（注意如果直接以「M = A;」來複製，則只會複製到參照）
		long[][] M = new long[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				M[i][j] = A[i][j];
			}
		}
		return M;
	}
	static long[][] multiplication(long[][] A, long[][] B) {
		// 回傳 3×3 矩陣 A, B 乘積的函式
		long[][] C = new long[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					C[i][j] += A[i][k] * B[k][j];
					C[i][j] %= MOD;
				}
			}
		}
		return C;
	}
	static long[][] power(long[][] A, long n) {
		// 回傳 A 的 n 次方的函式
		long[][] P = copyMatrix(A);
		long[][] Q = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
		boolean flag = false;
		for (int i = 0; i < 60; i++) {
			if ((n & (1L << i)) != 0L) {
				if (flag == false) {
					Q = copyMatrix(P);
					flag = true;
				}
				else {
					Q = copyMatrix(multiplication(Q, P));
				}
			}
			P = copyMatrix(multiplication(P, P));
		}
		return Q;
	}
}