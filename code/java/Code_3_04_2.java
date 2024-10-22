import java.util.*;

class Code_3_04_2 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] P = new int[N + 1];
		int[] Q = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			P[i] = sc.nextInt();
			Q[i] = sc.nextInt();
		}
		
		// 答案的計算、輸出
		double answer = 0.0;
		for (int i = 1; i <= N; i++) {
			answer += (double)Q[i] / P[i];
		}
		System.out.format("%.12f\n", answer);
	}
}
