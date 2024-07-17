import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int H = sc.nextInt(), W = sc.nextInt();
		int sx = sc.nextInt(), sy = sc.nextInt();
		int gx = sc.nextInt(), gy = sc.nextInt();
		String[] c = new String[H + 1];
		for (int i = 1; i <= H; i++) {
			c[i] = sc.next();
		}
		int start = (sx - 1) * W + sy;
		int goal = (gx - 1) * W + gy;
		
		// 製作鄰接表
		ArrayList<Integer>[] G = new ArrayList[H * W + 1];
		for (int i = 1; i <= H * W; i++) {
			G[i] = new ArrayList<Integer>();
		}
		
		// 將橫向的邊 [(i, j) - (i, j+1)] 添加到圖中
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W - 1; j++) {
				if (c[i].charAt(j - 1) == '.' && c[i].charAt(j) == '.') {
					int idx1 = (i - 1) * W + j; // 方格 (i, j) 的頂點編號
					int idx2 = (i - 1) * W + (j + 1); // 方格 (i, j + 1) 的頂點編號
					G[idx1].add(idx2);
					G[idx2].add(idx1);
				}
			}
		}
		
		// 將縱向的邊 [(i, j) - (i+1, j)] 添加到圖中
		for (int i = 1; i <= H - 1; i++) {
			for (int j = 1; j <= W; j++) {
				if (c[i].charAt(j - 1) == '.' && c[i + 1].charAt(j - 1) == '.') {
					int idx1 = (i - 1) * W + j; // 方格 (i, j) 的頂點編號
					int idx2 = i * W + j; // 方格 (i + 1, j) 的頂點編號
					G[idx1].add(idx2);
					G[idx2].add(idx1);
				}
			}
		}
		
		// 廣度優先搜尋的初始化 (dist[i] = -1 時，是未到達的白色頂點）
		int[] dist = new int[H * W + 1];
		for (int i = 1; i <= H * W; i++) {
			dist[i] = -1;
		}
		Queue<Integer> Q = new LinkedList<>(); // 定義佇列 Q
		dist[start] = 0;
		Q.add(start); // 於 Q 添加 start

		// 廣度優先搜尋
		while (Q.size() >= 1) {
			int pos = Q.remove(); // 查看 Q 的開頭並將其取出
			for (int i = 0; i < G[pos].size(); i++) {
				int nex = G[pos].get(i);
				if (dist[nex] == -1) {
					dist[nex] = dist[pos] + 1;
					Q.add(nex); // 於 Q 添加 nex
				}
			}
		}
		
		// 輸出答案
		System.out.println(dist[goal]);
	}
}
