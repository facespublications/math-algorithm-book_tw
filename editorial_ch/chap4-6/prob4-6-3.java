import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 計算答案
		final long MOD = 1000000007;
		long V = modpow(4, N + 1, MOD) - 1;
		long Answer = division(V, 3, MOD);
		
		// 輸出
		System.out.println(Answer);
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