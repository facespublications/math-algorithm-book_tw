import java.util.*;

class Code_2_06_1 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int S = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 搜尋全部模式：（1L << N）為 2 的 N 次方（ 1L 為表示 long 型的 1）
		String answer = "No";
		for (long i = 0; i < (1L << N); i++) {
			int sum = 0;
			for (int j = 1; j <= N; j++) {
				// (i & (1L << (j - 1))) != 0LL 時，i 的二進制表示的倒數第 j 位是 1
				// (1L << (j - 1)) 在 Java 中代表「2 的 j-1 次方」
				if ((i & (1L << (j - 1))) != 0L) {
					sum += A[j];
				}
			}
			if (sum == S) {
				answer = "Yes";
				break;
			}
		}
		
		// 輸出
		System.out.println(answer);
	}
}
