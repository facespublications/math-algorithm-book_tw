import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] X = new long[N];
		long[] Y = new long[N];
		for (int i = 1; i <= N; i++) {
			X[i - 1] = sc.nextLong();
			Y[i - 1] = sc.nextLong();
		}
		
		// 將陣列 X, Y 排序
		Arrays.sort(X);
		Arrays.sort(Y);
		
		// 部分 1 的答案（x座標的差的絕對值總和）
		long Part1 = 0;
		for (int i = 1; i <= N; i++) Part1 += X[i - 1] * (-N + 2L * i - 1L);
		
		// 部分 2 的答案（y 座標的差的絕對值總和）
		long Part2 = 0;
		for (int i = 1; i <= N; i++) Part2 += Y[i - 1] * (-N + 2L * i - 1L);
		
		// 輸出
		System.out.println(Part1 + Part2);
	}
}