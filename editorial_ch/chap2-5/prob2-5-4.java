import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 輸入
		int N = sc.nextInt();
		
		// 輸出
		for (int i = 2; i <= N; i++) {
			if (isPrime(i) == true) {
				if (i >= 3) System.out.print(" ");
				System.out.print(i);
			}
		}
		System.out.println();
	}
	static boolean isPrime(long N) {
		// 對 2 以上的整數，若 N 為質數時回傳 true，非質數時回傳 false 的函數
		for (long i = 2; i <= N - 1; i++) {
			if (N % i == 0) {
				return false;
			}
		}
		return true;
	}
}