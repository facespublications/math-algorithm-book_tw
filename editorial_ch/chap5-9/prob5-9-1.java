import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long Answer = 0;
		
		// 支付 10000 日圓鈔
		Answer += (N / 10000); N %= 10000;
		
		// 支付 5000 日圓鈔
		Answer += (N / 5000); N %= 5000;
		
		// 支付 1000 日圓鈔
		Answer += (N / 1000); N %= 1000;
		
		// 輸出
		System.out.println(Answer);
	}
}