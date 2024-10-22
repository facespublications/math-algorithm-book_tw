import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		int[] B = new int[N];
		for (int i = 1; i <= N - 1; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
		}
		
		// 製作鄰接表
		G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= N - 1; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 使用深度優先搜尋的動態規劃法
		visited = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
		dp = new int[N + 1];
		dfs(1);

		// 計算答案並輸出
		long answer = 0;
		for (int i = 2; i <= N; i++) {
			answer += (long)dp[i] * (N - dp[i]);
		}
		System.out.println(answer);
	}
	
	static boolean[] visited;
	static int[] dp;
	static ArrayList<Integer>[] G;
	static void dfs(int pos) {
		visited[pos] = true;
		dp[pos] = 1;
		for (int i : G[pos]) {
			if (visited[i] == false) {
				dfs(i);
				dp[pos] += dp[i];
			}
		}
	}
}