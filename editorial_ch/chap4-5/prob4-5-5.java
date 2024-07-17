import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[] A = new int[M + 1];
		int[] B = new int[M + 1];
		for (int i = 1; i <= M; i++) {
			A[i] = sc.nextInt();
			B[i] = sc.nextInt();
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
		
		// 求出答案
		int answer = 0;
		for (int i = 1; i <= N; i++) {
			int cnt = 0;
			for (int j = 0; j < G[i].size(); j++) {
				// G[i].get(j) 是與頂點 i 鄰接的頂點中第 j+1 個
				if (G[i].get(j) < i) {
					cnt += 1;
				}
			}
			// 如果比自己的編號小的鄰接頂點為 1 個的話，將 answer 加 1
			if (cnt == 1) {
				answer += 1;
			}
		}
		
		// 輸出答案
		System.out.println(answer);
	}
}
