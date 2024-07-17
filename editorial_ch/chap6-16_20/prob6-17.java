import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 將垂直長度從 1 到 √N 為止進行全搜尋
		long answer = (1L << 60);
		for (long x = 1; x * x <= N; x++) {
			if (N % x == 0) {
				answer = Math.min(answer, 2 * x + 2 * (N / x));
			}
		}
		
		// 輸出答案
		System.out.println(answer);
	}
}