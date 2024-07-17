import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 輸入
		long N = sc.nextInt();

		// 計算答案
		long Answer = 1;
		for (int i = 1; i <= N; i++) Answer *= i;

		// 輸出
		System.out.println(Answer);
	}
};