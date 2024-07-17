import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		
		// 製作鄰接表
		ArrayList<PairInt>[] G = new ArrayList[K];
		for (int i = 0; i < K; i++) {
			G[i] = new ArrayList<PairInt>();
		}
		
		// 添加圖形的邊
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < 10; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				G[i].add(new PairInt((i * 10 + j) % K, j));
			}
		}
		
		// Dijkstra法：陣列的初始化等
		int[] dist = new int[K];
		boolean[] used = new boolean[K];
		for (int i = 0; i < K; i++) {
			dist[i] = (1 << 30);
			used[i] = false;
		}
		Queue<PairInt> Q = new PriorityQueue<PairInt>();
		Q.add(new PairInt(0, 0)); // 注意此處勿使 dist[0] = 0 ！
		
		// Dijkstra法：優先佇列的更新
		while (Q.size() >= 1) {
			int pos = Q.poll().second;
			if (used[pos] == true) {
				continue;
			}
			used[pos] = true;
			for (PairInt i : G[pos]) {
				int to = i.first;
				int cost = dist[pos] + i.second;
				if (pos == 0) {
					cost = i.second; // 頂點 0 時為例外
				}
				if (dist[to] > cost) {
					dist[to] = cost;
					Q.add(new PairInt(dist[to], to));
				}
			}
		}
		
		// 輸出答案
		System.out.println(dist[0]);
	}
	
	// int 型態配對的類別 PairInt
	static class PairInt implements Comparable<PairInt> {
		int first, second;
		public PairInt(int first_, int second_) {
			super();
			this.first = first_;
			this.second = second_;
		}
		@Override public int compareTo(PairInt p) {
			// 將 PairInt 型態彼此進行比較的函式
			if (this.first < p.first || (this.first == p.first && this.second < p.second)) {
				return -1;
			}
			if (this.first > p.first || (this.first == p.first && this.second > p.second)) {
				return 1;
			}
			return 0;
		}
	}
}
