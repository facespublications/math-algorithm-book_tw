import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 輸出
		System.out.println(N * (N - 1) / 2);
	}
}