import java.util.*;

class Code_3_06_5 {
	static int N;
	static int[] A;
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 遞迴呼叫→輸出答案
		int answer = solve(1, N + 1);
		System.out.println(answer);
	}
	static int solve(int l, int r) {
		if (r - l == 1) {
			return A[l];
		}
		int m = (l + r) / 2; // 在區間 [l,r)的中央進行分割
		int s1 = solve(l, m); // s1為 A[l]+...+A[m-1]的合計值
		int s2 = solve(m, r); // s2為 A[m]+...+A[r-1] 的合計值
		return s1 + s2;
	}
}
