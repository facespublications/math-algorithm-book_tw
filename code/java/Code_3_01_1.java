import java.util.*;

class Code_3_01_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		boolean answer = isPrime(N);
		if (answer == true) {
			System.out.println("prime");
		}
		else {
			System.out.println("not prime");
		}
	}
	static boolean isPrime(long N) {
		// 設 N 為 2 以上整數，若 N 為質數則返回 true，若不是質數則返回 false
		for (long i = 2; i <= N - 1; i++) {
			if (N % i == 0) {
				return false; // N 被 i 整除時，此時可知不是質數
			}
		}
		return true;
	}
}
