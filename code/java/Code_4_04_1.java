import java.util.*;

class Code_4_04_1 {
	public static void main(String[] args) {
		// 輸入 → 陣列 prime 的初始化
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		boolean[] prime = new boolean[N + 1];
		for (int i = 2; i <= N; i++) {
			prime[i] = true;
		}
		
		// 埃拉托斯特尼篩
		for (int i = 2; i * i <= N; i++) {
			if (prime[i] == true) {
				for (int x = 2 * i; x <= N; x += i) {
					prime[x] = false;
				}
			}
		}
		
		// 將 N 以下的質數以從小到大的順序輸出
		for (int i = 2; i <= N; i++) {
			if (prime[i] == true) {
				System.out.println(i);
			}
		}
	}
}
