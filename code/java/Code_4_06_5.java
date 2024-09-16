import java.util.*;

class Code_4_06_5 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		// 求出二項係數的分子和分母（步驟1./ 步驟2.）
		final long MOD = 1000000007;
		long bunshi = 1, bunbo = 1;
		for (int i = 1; i <= X + Y; i++) {
			bunshi = (bunshi * i) % MOD;
		}
		for (int i = 1; i <= X; i++) {
			bunbo = (bunbo * i) % MOD;
		}
		for (int i = 1; i <= Y; i++) {
			bunbo = (bunbo * i) % MOD;
		}
		
		// 求出答案（步驟3.）
		long answer = division(bunshi, bunbo, MOD);
		System.out.println(answer);
	}
	static long modpow(long a, long b, long m) {
		// 重複平方法（p 取 a^1、a^2、 a^4、a^8、⋯的值）
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
		// division(a, b, m) 是回傳　a÷b mod m 的函式
		return (a * modpow(b, m - 2, m)) % m;
	}
}
