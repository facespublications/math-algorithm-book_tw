import java.util.*;

class Code_3_01_2 {
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
		// 設 N 為 2 以上整數，若 N 為質數則返回true，若不是質數則返回false
		for (long i = 2; i * i <= N; i++) {
			if (N % i == 0) {
				return false;
			}
		}
		return true;
	}
}
