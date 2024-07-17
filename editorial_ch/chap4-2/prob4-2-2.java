import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] A = new int[500009];
		int[] B = new int[500009];
		int[] L = new int[500009];
		int[] R = new int[500009];
		
		// 輸入
		int T = sc.nextInt();
		int N = sc.nextInt();
		for (int i = 1; i <= N; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}
		
		// 計算階差 B[i]
		for (int i = 0; i <= T; i++) B[i] = 0;
		for (int i = 1; i <= N; i++) {
			B[L[i]] += 1;
			B[R[i]] -= 1;
		}
		
		// 計算累積和 A[i]
		A[0] = B[0];
		for (int i = 1; i < T; i++) {
			A[i] = A[i - 1] + B[i];
		}
		
		// 輸出答案
		for (int i = 0; i < T; i++) {
			System.out.println(A[i]);
		}
	}
}