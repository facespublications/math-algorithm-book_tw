import java.util.*;

class Code_4_07_1 {
	public static void main(String[] args) {
		// 輸入　→　乘方的計算（請注意，N 必須大於 2 才能正常運作）
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long[][] A = new long[2][2];
		A[0][0] = 1; A[0][1] = 1;
		A[1][0] = 1; A[1][1] = 0;
		long[][] B = copyMatrix(power(A, N - 1));
		
		// 輸出（請注意，倒數第 9 位為 0 時，以開頭不含 0 的形式輸出）
		long answer = (B[1][0] + B[1][1]) % MOD;
		System.out.println(answer);
	}
	static final int MOD = 1000000000;
	static long[][] copyMatrix(long[][] A) {
		// 複製矩陣（請留意若直接複製「M = A;」的話，只會複製參照）
		long[][] M = new long[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				M[i][j] = A[i][j];
			}
		}
		return M;
	}
	static long[][] multiplication(long[][] A, long[][] B) {
		// 回傳　2×2 矩陣 A、B 乘積的函式
		long[][] C = new long[2][2];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
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
		long[][] Q = { { 0, 0 }, { 0, 0 } };
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
