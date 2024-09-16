import java.util.*;

class Code_3_02_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		System.out.println(GCD(A, B));
	}
	static long GCD(long A, long B) {
		// 返回正整數 A 和 B 的最大公因數的函式
		// GCD 是Greatest Common Divisor（最大公因數）的縮寫
		long ans = 0;
		for (long i = 1; i <= A && i <= B; i++) {
			if (A % i == 0 && B % i == 0) {
				ans = i;
			}
		}
		return ans;
	}
}
