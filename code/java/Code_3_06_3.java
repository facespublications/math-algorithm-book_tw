import java.util.*;

class Code_3_06_3 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		System.out.println(func(N));
	}
	static int func(int N) {
		if (N == 1) {
			return 1; // 這種要區分開的情況稱為「基本情況」
		}
		return func(N - 1) * N;
	}
}
