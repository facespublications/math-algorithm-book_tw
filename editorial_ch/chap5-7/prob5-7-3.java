import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];
		for (int i = 1; i <= N; i++) {
			A[i - 1] = sc.nextLong();
		}
		
		// 將陣列 A 全部排序
		Arrays.sort(A);
		
		// 求出答案
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += A[i - 1] * (-N + 2L * i - 1L);
		}
		
		// 輸出
		System.out.println(Answer);
	}
}