import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		long[] C = new long[M + 1];
		for (int i = 1; i <= M; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
			C[i] = sc.nextLong();
		}
		
		// 製作鄰接表
		ArrayList<PairLong>[] G = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) {
			G[i] = new ArrayList<PairLong>();
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(new PairLong((long)B[i], C[i]));
			G[B[i]].add(new PairLong((long)A[i], C[i]));
		}
		
		// Dijkstra法：陣列的初始化等
		long[] dist = new long[N + 1];
		boolean[] used = new boolean[N + 1];
		for (int i = 1; i <= N; i++) {
			dist[i] = (1L << 60);
			used[i] = false;
		}
		Queue<PairLong> Q = new PriorityQueue<PairLong>();
		dist[1] = 0L;
		Q.add(new PairLong(0L, (long)1));
		
		// Dijkstra法：更新優先佇列
		while (Q.size() >= 1) {
			int pos = (int)Q.poll().second;
			if (used[pos] == true) {
				continue;
			}
			used[pos] = true;
			for (PairLong i : G[pos]) {
				int to = (int)i.first;
				long cost = dist[pos] + i.second;
				if (dist[to] > cost) {
					dist[to] = cost;
					Q.add(new PairLong(dist[to], (long)to));
				}
			}
		}
		
		// 輸出答案
		if (dist[N] != (1L << 60)) {
			System.out.println(dist[N]);
		}
		else {
			System.out.println(-1);
		}
	}
	
	// long 型態的配對類型 PairLong
	static class PairLong implements Comparable<PairLong> {
		long first, second;
		public PairLong(long first_, long second_) {
			super();
			this.first = first_;
			this.second = second_;
		}
		@Override public int compareTo(PairLong p) {
			// 進行 PairLong 型態彼此間比較的函式
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