import java.util.*;

class Code_4_05_1 {
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
			G[i] = new ArrayList<Integer>(); // G[i] 是與頂點 i 相鄰頂點的列表
		}
		for (int i = 1; i <= M; i++) {
			G[A[i]].add(B[i]); // 添加 B[i] 作為與頂點 A[i] 相鄰的頂點
			G[B[i]].add(A[i]); // 添加 A[i] 作為與頂點 B[i] 相鄰的頂點
		}
		
		// 輸出（G[i].size() 為與頂點i 相鄰頂點的列表的大小 = 度）
		for (int i = 1; i <= N; i++) {
			System.out.format("%d: {", i);
			for (int j = 0; j < G[i].size(); j++) {
				if (j >= 1) {
					System.out.print(",");
				}
				System.out.print(G[i].get(j)); // G[i].get(j) 是與頂點　i 相鄰頂點之中的第 j+1 個頂點
			}
			System.out.println("}");
		}
	}
}
