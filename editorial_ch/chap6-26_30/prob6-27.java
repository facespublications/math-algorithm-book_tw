import java.util.*;

class Main {
	public static void main(String[] args) {
		// 陣列 fact 的初始化（fact[i] 為將 i 的階乘除以 1000000007 的餘數）
		fact = new long[LIMIT + 1];
		fact[0] = 1;
		for (int i = 1; i <= LIMIT; i++) {
			fact[i] = fact[i - 1] * i % MOD;
		}
		
		// 輸入 → 計算答案並輸出
		Scanner	sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int i = 1; i <= N; i++) {
			int answer = 0;
			for (int j = 1; i * (j - 1) < N; j++) {
				answer += ncr(N - (i - 1) * (j - 1), j);
				answer %= MOD;
			}
			System.out.println(answer);
		}
	}
	static final long MOD = 1000000007;
	static final int LIMIT = 100000;
	static long[] fact;
	static long modpow(long a, long b, long m) {
		// 重複平方法（p 取 a^1, a^2, a^4, a^8, ... 等值）
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
		// division(a, b, m) 是回傳 a÷b mod m 的函式
		return (a * modpow(b, m - 2, m)) % m;
	}
	static long ncr(int n, int r) {
		// ncr 是將 n! 除以 r! × (n-r)! 的值
		return division(fact[n], fact[r] * fact[n - r] % MOD, MOD);
	}
}