import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		// 狀況區分（a, b 會變成負的時候）
		if ((2 * Y - X) < 0 || (2 * X - Y) < 0) {
			System.out.println("0");
		}
		
		// 狀況區分（a, b 不會成為整數的時候）
		else if ((2 * Y - X) % 3 != 0 || (2 * X - Y) % 3 != 0) {
			System.out.println("0");
		}
		
		// 答案不為零時
		else {
			long MOD = 1000000007;
			long bunshi = 1, bunbo = 1;
			long a = (2 * Y - X) / 3;
			long b = (2 * X - Y) / 3;
			
			// 求出二項係數的分子與分母（步驟 1.／步驟 2.）
			for (int i = 1; i <= a + b; i++) {
				bunshi = (bunshi * i) % MOD;
			}
			for (int i = 1; i <= a; i++) {
				bunbo = (bunbo * i) % MOD;
			}
			for (int i = 1; i <= b; i++) {
				bunbo = (bunbo * i) % MOD;
			}
			
			// 求出答案（步驟 3.）
			long answer = division(bunshi, bunbo, MOD);
			System.out.println(answer);
		}
	}
	static long modpow(long a, long b, long m) {
		// 重複平方法（p 取如 a^1, a^2, a^4, a^8, ... 的值）
		long p = a, answer = 1;
		for (int i = 0; i < 30; i++) {
			if ((b & (1 << i)) != 0) {
				answer = (answer * p) % m;
			}
			p = (p * p) % m;
		}
		return answer;
	}
	static long division(long a, long b, long m) {
		// division(a, b, m) 為傳回 a÷b mod m 的函式
		return (a * modpow(b, m - 2, m)) % m;
	}
}