import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long L = sc.nextLong();
		long R = sc.nextLong();
		int D = (int)(R - L);
		
		// 陣列的初始化
		boolean[] isprime = new boolean[D + 1];
		for (int i = 0; i <= D; i++) {
			isprime[i] = true;
		}

		// 區分出 L = 1 時的狀況（邊角案例）
		if (L == 1) {
			isprime[0] = false;
		}
		
		// 篩選
		for (int i = 2; (long)i * i <= R; i++) {
			int start = (int)(((L + i - 1) / i * i) - L); // (在 L 以上之最小的 i 的倍數) - L
			// 將 L 以上 R 以下的所有（除 i 以外的）i 的倍數標記為×
			for (int j = start; j <= D; j += i) {
				if (j + L == (long)i) continue;
				isprime[j] = false;
			}
		}
		
		// 計數個數並輸出
		int answer = 0;
		for (int i = 0; i <= D; i++) {
			if (isprime[i] == true) {
				answer += 1;
			}
		}
		System.out.println(answer);
	}
}