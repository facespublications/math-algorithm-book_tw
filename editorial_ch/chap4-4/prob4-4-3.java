import java.util.*;
 
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 輸入 → 陣列的初始化
		int N = sc.nextInt();
		long[] F = new long[N + 1];
		for (int i = 1; i <= N; i++) F[i] = 0;
		
		// 計算 F[1], F[2], ..., F[N]
		for (int i = 1; i <= N; i++) {
			// 對 F[i], F[2i], F[3i], ... 加算 1
			for (int j = i; j <= N; j += i) F[j] += 1;
		}
		
		// 求出答案
		long Answer = 0;
		for (int i = 1; i <= N; i++) {
			Answer += F[i] * i;
		}
		System.out.println(Answer);
	}
}