import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		int K = sc.nextInt();
		long[] V = new long[K + 1];
		for (int i = 1; i <= K; i++) {
			V[i] = sc.nextLong();
		}
		
		// 位元全搜尋
		long Answer = 0;
		for (int i = 1; i < (1 << K); i++) {
			int cnt = 0; // 選擇數字的個數
			long lcm = 1; // 最小公倍數
			for (int j = 0; j < K; j++) {
				if ((i & (1 << j)) != 0) {
					cnt += 1;
					lcm = LCM(lcm, V[j + 1]);
				}
			}
			long num = N / lcm; // 數的個數，此數是被選擇的所有數字的倍數
			if (cnt % 2 == 1) Answer += num;
			if (cnt % 2 == 0) Answer -= num;
		}
		
		// 輸出
		System.out.println(Answer);
	}
	static long GCD(long A, long B) {
		// 回傳最大公因數的函式
		if (B == 0) return A;
		return GCD(B, A % B);
	}
	static long LCM(long A, long B) {
		// 回傳最小公倍數的函式
		return (A / GCD(A, B)) * B;
	}
}