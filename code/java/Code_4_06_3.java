import java.util.*;

class Code_4_06_3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		final long MOD = 1000000007;
		long a = sc.nextLong();
		long b = sc.nextLong();
		long answer = 1; // a　的 0 次方為 1，因此初始化成 answer=1
		for (long i = 1; i <= b; i++) {
			answer = (answer * a) % MOD;
		}
		System.out.println(answer);
	}
}
