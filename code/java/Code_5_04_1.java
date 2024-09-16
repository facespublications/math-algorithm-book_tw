import java.util.*;

class Code_5_04_1 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		// 算出事件 B 的個數 yojishou
		long yojishou = 0;
		for (int a = 1; a <= N; a++) {
			int l = Math.max(1, a - (K - 1)); // b, c 的搜尋範圍下限 l
			int r = Math.min(N, a + (K - 1)); // b, c 的搜尋範圍上限 r
			for (int b = l; b <= r; b++) {
				for (int c = l; c <= r; c++) {
					if (Math.abs(b - c) <= K - 1) {
						yojishou += 1;
					}
				}
			}
		}
		// 答えの出力
		long answer = (long)N * N * N - yojishou;
		System.out.println(answer);
	}
}
