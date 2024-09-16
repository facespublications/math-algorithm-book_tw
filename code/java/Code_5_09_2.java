import java.util.*;

class Code_5_09_2 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] L = new int[N + 1];
		int[] R = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			L[i] = sc.nextInt();
			R[i] = sc.nextInt();
		}
		
		// 模擬電影的選擇方法
		// 可觀看電影的結束時間最小值 minEndtime は、最初是設定成像 1000000 (以 INF 設定）這樣不可能的值
		final int INF = 1000000;
		int currentTime = 0; // currentTime 為現在時間（之前看完的電影的結束時間）
		int answer = 0;
		while (true) {
			int minEndtime = INF;
			for (int i = 1; i <= N; i++) {
				if (L[i] >= currentTime) {
					minEndtime = Math.min(minEndtime, R[i]);
				}
			}
			if (minEndtime == INF) {
				break;
			}
			currentTime = minEndtime;
			answer += 1;
		}
		
		// 輸出答案
		System.out.println(answer);
	}
}
