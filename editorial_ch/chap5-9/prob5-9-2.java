import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];
		long[] B = new long[N];
		for (int i = 1; i <= N; i++) A[i - 1] = sc.nextLong();
		for (int i = 1; i <= N; i++) B[i - 1] = sc.nextLong();
		
		// 將陣列 A, B 排序
		Arrays.sort(A);
		Arrays.sort(B);
		
		// 求出答案
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += Math.abs(A[i - 1] - B[i - 1]);
		}
		
		// 輸出
		System.out.println(Answer);
	}
}