import java.util.*;
import java.io.*;

class Code_4_05_2 {
	public static void main(String[] args) throws IOException {
		// 輸入（由於是高速的輸入輸出，因此使用　BufferedReader　代替　Scanner）
		BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(buff.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			st = new StringTokenizer(buff.readLine());
			A[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
		}
		
		// 製作鄰接表
		G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 深度優先搜尋
		visited = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
		dfs(1);

		// 判定是否連通（answer=true 時為連通）
		boolean answer = true;
		for (int i = 1; i <= N; i++) {
			if (visited[i] == false) {
				answer = false;
			}
		}
		if (answer == true) {
			System.out.println("The graph is connected.");
		}
		else {
			System.out.println("The graph is not connected.");
		}
	}
	
	static boolean[] visited;
	static ArrayList<Integer>[] G;
	static void dfs(int pos) {
		visited[pos] = true;
		for (int i : G[pos]) {
			if (visited[i] == false) {
				dfs(i);
			}
		}
	}
}
