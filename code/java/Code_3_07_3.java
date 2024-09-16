import java.util.*;

class Code_3_07_3 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int W = sc.nextInt();
		int[] w = new int[N + 1];
		int[] v = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			w[i] = sc.nextInt();
			v[i] = sc.nextInt();
		}
		
		// 陣列的初始化
		long INF = 1000000000000000000L;
		long[][] dp = new long[N + 1][W + 1];
		dp[0][0] = 0;
		for (int i = 1; i <= W; i++) {
			dp[0][i] = -INF;
		}
		
		// 動態規劃法
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= W; j++) {
				if (j < w[i]) {
					// j < w[i] 時，只能選擇方法 A
					dp[i][j] = dp[i - 1][j];
				}
				else {
					// j >= w[i] 時，可以選擇方法 A、方法 B 的任一個
					dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
				}
			}
		}
		
		// 計算並輸出答案
		long answer = 0;
		for (int i = 0; i <= W; i++) {
			answer = Math.max(answer, dp[N][i]);
		}
		System.out.println(answer);
	}
}
