import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] B = new int [200009];
		long[] A = new long [200009];
		long[] S = new long [200009];
		
		// 輸入
		int N = sc.nextInt();
		for (int i = 1; i <= N - 1; i++) A[i] = sc.nextLong();
		int M = sc.nextInt();
		for (int i = 1; i <= M; i++) B[i] = sc.nextInt();
		
		// 取累積和
		S[1] = 0;
		for (int i = 2; i <= N; i++) S[i] = S[i - 1] + A[i - 1];
		
		// 求出答案
		long Answer = 0;
		for (int i = 1; i <= M - 1; i++) {
			if (B[i] < B[i + 1]) {
				Answer += (S[B[i + 1]] - S[B[i]]);
			}
			else {
				Answer += S[B[i]] - S[B[i + 1]];
			}
		}
		
		// 輸出
		System.out.println(Answer);
	}
}