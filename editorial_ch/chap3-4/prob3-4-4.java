import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		// 計算答案
		double Answer = 0.0;
		for (int i = N; i >= 1; i--) {
			Answer += 1.0 * N / i;
		}
		
		// 輸出
		System.out.format("%.12f\n", Answer);
	}
}