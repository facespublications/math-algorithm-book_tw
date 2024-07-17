import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 輸入（由於是高速的輸入輸出，使用 BufferedReader 來取代 Scanner）
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
		color = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			color[i] = 0;
		}
		for (int i = 1; i <= N; i++) {
			if (color[i] == 0) {
				// 頂點 i 為白（尚未搜尋的連通成分）
				color[i] = 1;
				dfs(i);
			}
		}

		// 是否為二部圖的判斷
		boolean answer = true;
		for (int i = 1; i <= M; i++) {
			if (color[A[i]] == color[B[i]]) {
				answer = false;
			}
		}
		if (answer == true) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
	
	static int[] color;
	static ArrayList<Integer>[] G;
	static void dfs(int pos) {
		for (int i : G[pos]) {
			if (color[i] == 0) {
				// color[pos] = 1 的時候為 2，color[pos] = 2 的時候為 1
				color[i] = 3 - color[pos];
				dfs(i);
			}
		}
	}
}
