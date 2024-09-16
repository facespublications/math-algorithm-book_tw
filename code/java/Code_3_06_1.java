import java.util.*;

class Code_3_06_1 {
	public static void main(String[] args) {
		// 輸入（例如輸入了 N = 5, A = [3, 1, 4, 1, 5] ）
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N];
		for (int i = 1; i <= N; i++) {
			A[i - 1] = sc.nextInt();
		}
		
		// 排序陣列 A 整體
		Arrays.sort(A);
		
		// 輸出（按照1、1、3、4、5 的順序輸出）
		for (int i = 1; i <= N; i++) {
			System.out.println(A[i - 1]);
		}
	}
}
