import java.util.*;

class Code_3_01_3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		for (long i = 1; i * i <= N; i++) {
			if (N % i == 0) {
				System.out.println(i); // 追加因數 i
				if (i != N / i) {
					System.out.println(N / i); // i ≠ N/i 時，也追加因數 N/i
				}
			}
		}
	}
}
