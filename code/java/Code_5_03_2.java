import java.util.*;

class Code_5_03_2 {
	public static void main(String[] args) {
		// 輸入 → 求數列元素的總和sum
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int K = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += A[i];
		}
		
		// 輸出答案
		if (sum % 2 != K % 2) {
			System.out.println("No");
		}
		else if (sum > K) {
			System.out.println("No");
		}
		else {
			System.out.println("Yes");
		}
	}
}
