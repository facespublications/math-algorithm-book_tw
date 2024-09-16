// 這個原始碼為將深度優先搜尋 (DFS) 使用了堆疊的實作例。
// 堆疊為可進行「在最上層堆積元素」、「查找堆積在最上層的元素」、「刪除堆積在最上層的元素」三種操作的資料結構。
// 深度優先搜尋的部分為將程式碼 4.5.3 的 queue 變更為 stack，以此為基礎撰寫。

import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws IOException {
		// 輸入（由於是高速的輸入輸出，使用 BufferedReader 代替 Scanner）
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
		ArrayList<Integer>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<Integer>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]);
			G[B[i]].add(A[i]);
		}
		
		// 深度優先搜尋的初始化
		boolean[] visited = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			visited[i] = false;
		}
		Stack<Integer> S = new Stack<>(); // 定義堆疊 S 
		visited[1] = true;
		S.push(1); // S 追加 1

		// 深度優先搜尋
		while (S.size() >= 1) {
			int pos = S.pop(); // 調查 S 的開頭並將之取出
			for (int nex : G[pos]) {
				if (visited[nex] == false) {
					visited[nex] = true;
					S.push(nex); // 追加 nex 至 S
				}
			}
		}
		
		// 判定是否連通（answer = true 時為連通）
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
}
