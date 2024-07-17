import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		
		// 陣列的初始化
		long[] First = new long[N + 1];
		long[] Second = new long[N + 1];
		for (int i = 1; i <= N; i++) First[i] = -1;
		for (int i = 1; i <= N; i++) Second[i] = -1;
		
		// 求出答案（cur 為現在所在城鎮的編號）
		long cnt = 0;
		int cur = 1;
		while (true) {
			// First, Second 更新
			if (First[cur] == -1) First[cur] = cnt;
			else if (Second[cur] == -1) Second[cur] = cnt;
			
			// 判斷在 K 次移動後是否位在城鎮 cur 
			if (cnt == K) {
				System.out.println(cur);
				System.exit(0);
			}
			else if (Second[cur] != -1L && (K - First[cur]) % (Second[cur] - First[cur]) == 0) {
				System.out.println(cur);
				System.exit(0);
			}
			
			// 移動
			cur = A[cur];
			cnt += 1;
		}
	}
}