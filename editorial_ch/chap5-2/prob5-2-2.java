import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 檢查是否以 N = 2^k-1 的形式表示
		boolean flag = false;
		for (int i = 1; i <= 60; i++) {
			if (N == (1L << i) - 1) {
				flag = true;
			}
		}
		
		// 輸出
		if (flag == true) System.out.println("Second");
		else System.out.println("First");
	}
}