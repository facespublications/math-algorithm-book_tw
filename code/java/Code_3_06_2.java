import java.util.*;

class Code_3_06_2 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextInt();
		}
		
		// 選擇排序
		for (int i = 1; i <= N - 1; i++) {
			int minPosition = i;
			int minValue = A[i];
			for (int j = i + 1; j <= N; j++) {
				if (A[j] < minValue) {
					minPosition = j; // minPosition 為最小值的索引（1 ∼ N）
					minValue = A[j]; // minValue 為當下的最小值
				}
			}
			// 用以下 3 行交換 A[i] 與 A[minPosition] 
			int temp = A[i];
			A[i] = A[minPosition];
			A[minPosition] = temp;
		}
		
		// 輸出
		for (int i = 1; i <= N; i++) {
			System.out.println(A[i]);
		}
	}
}
