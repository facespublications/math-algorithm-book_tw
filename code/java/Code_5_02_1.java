import java.util.*;

class Code_5_02_1 {
	public static void main(String[] args) {
		// 注意：以下的程式需要 N >= 1 才能正確動作。N = 0 會使答案為「1」，需要另外分開處理。
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		if (N % 4 == 1) {
			System.out.println(2);
		}
		if (N % 4 == 2) {
			System.out.println(4);
		}
		if (N % 4 == 3) {
			System.out.println(8);
		}
		if (N % 4 == 0) {
			System.out.println(6);
		}
	}
}
