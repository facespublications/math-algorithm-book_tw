import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 輸入
		int N = sc.nextInt();
		int S = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 陣列的初始化
		boolean[][] dp = new boolean[N + 1][S + 1];
		dp[0][0] = true;
		for (int i = 1; i <= S; i++) {
			dp[0][i] = false;
		}
		
		// 動態規劃法
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= S; j++) {
				if (j < A[i]) {
					// j < A[i] 時，無法選擇卡 i
					dp[i][j] = dp[i - 1][j];
				}
				else {
					// j >= A[i] 時，有選擇 / 不選擇 兩種選項
					if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = false;
					}
				}
			}
		}
		
		// 計算答案並輸出
		if (dp[N][S] == true) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}