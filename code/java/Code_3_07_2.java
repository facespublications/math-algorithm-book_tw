import java.util.*;

class Code_3_07_2 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		// 動態規劃法
		int[] dp = new int[N + 1];
		for (int i = 0; i <= N; i++) {
			if (i <= 1) {
				dp[i] = 1;
			}
			else {
				dp[i] = dp[i - 1] + dp[i - 2];
			}
		}
		
		// 輸出答案
		System.out.println(dp[N]);
	}
}
