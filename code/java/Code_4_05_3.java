import java.util.*;
import java.io.*;

class Code_4_05_3 {
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
		
		// 廣度優先搜尋的初始化（dist[i]=-1 時，為未到達的白色頂點）
		int[] dist = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			dist[i] = -1;
		}
		Queue<Integer> Q = new LinkedList<>(); // 定義佇列Q
		dist[1] = 0;
		Q.add(1); // 將 1 添加到 Q 中（操作 1）

		// 廣度優先搜尋
		while (Q.size() >= 1) {
			int pos = Q.remove(); // 查看 Q 的開頭並將之取出（操作2,3）
			for (int i = 0; i < G[pos].size(); i++) {
				int nex = G[pos].get(i);
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex); // 將　nex 添加到Q 中（操作 1）
				}
			}
		}
		
		// 輸出從頂點　1 到各頂點的最短距離
		for (int i = 1; i <= N; i++) {
			System.out.println(dist[i]);
		}
	}
}
