import java.util.*;

class Code_3_02_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		System.out.println(GCD(A, B));
	}
	static long GCD(long A, long B) {
		// 返回正整數 A 和 B 的最大公因數的函式
		// GCD 是Greatest Common Divisor（最大公因數）的縮寫
		while (A >= 1 && B >= 1) {
			if (A < B) {
				B %= A; // A < B時，改寫較大的數B
			}
			else {
				A %= B; // A >= B時，改寫較大的數A
			}
		}
		if (A >= 1) {
			return A;
		}
		return B;
	}
}
