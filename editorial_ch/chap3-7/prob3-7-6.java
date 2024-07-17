import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 輸入
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 陣列的初始化
		long[] dp1 = new long[N + 1];
		long[] dp2 = new long[N + 1];
		dp1[0] = 0;
		dp2[0] = 0;
		
		// 動態規劃法
		for (int i = 1; i <= N; i++) {
			dp1[i] = dp2[i - 1] + A[i];
			dp2[i] = Math.max(dp1[i - 1], dp2[i - 1]);
		}
		
		// 計算答案並輸出
		long Answer = Math.max(dp1[N], dp2[N]);
		System.out.println(Answer);
	}
}