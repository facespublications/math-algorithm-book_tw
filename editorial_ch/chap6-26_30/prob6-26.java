import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int Q = sc.nextInt();
		for (int t = 1; t <= Q; t++) {
			// 輸入 → 建構矩陣 A
			double X = sc.nextDouble();
			double Y = sc.nextDouble();
			double Z = sc.nextDouble();
			int T = sc.nextInt();
			double[][] A = {
				{ 1 - X, Y, 0 },
				{ 0, 1 - Y, Z },
				{ X, 0, 1 - Z }
			};

			// 矩陣乘方的計算 → 輸出答案
			double[][] B = copyMatrix(power(A, T));
			double answerA = B[0][0] + B[0][1] + B[0][2];
			double answerB = B[1][0] + B[1][1] + B[1][2];
			double answerC = B[2][0] + B[2][1] + B[2][2];
			System.out.format("%.12f %.12f %.12f\n", answerA, answerB, answerC);
		}
	}
	static final int MOD = 1000000000;
	static double[][] copyMatrix(double[][] A) {
		// 矩陣的複製（注意如果直接以「M = A;」來複製，則只會複製到參照）
		double[][] M = new double[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				M[i][j] = A[i][j];
			}
		}
		return M;
	}
	static double[][] multiplication(double[][] A, double[][] B) {
		// 回傳 3×3 矩陣 A, B 乘積的函式
		double[][] C = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return C;
	}
	static double[][] power(double[][] A, int n) {
		// 回傳 A 的 n 次方的函式
		double[][] P = copyMatrix(A);
		double[][] Q = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
		boolean flag = false;
		for (int i = 0; i < 30; i++) {
			if ((n & (1 << i)) != 0L) {
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