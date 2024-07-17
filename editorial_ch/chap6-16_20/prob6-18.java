import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		
		// 判斷最小公倍數是否超過 10^18
		if (A / GCD(A, B) > 1000000000000000000L / B) {
			System.out.println("Large");
		}
		else {
			System.out.println(A / GCD(A, B) * B);
		}
	}
	static long GCD(long A, long B) {
		if (B == 0) return A;
		return GCD(B, A % B);
	}
}