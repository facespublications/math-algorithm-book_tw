import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		double[] A = new double[N + 1];
		double[] B = new double[N + 1];
		double[] C = new double[N + 1];
		for (int i = 1; i <= N; i++) {
			A[i] = sc.nextDouble();
			B[i] = sc.nextDouble();
			C[i] = sc.nextDouble();
		}
		
		// 將交點進行全搜尋
		double Answer = 0.0;
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				// 不具有交點時
				if (A[i] * B[j] == A[j] * B[i]) continue;
				
				// 求出第 i 條直線（條件式的邊界）與第 j 條直線（條件式的邊界）的交點
				double px = (C[i] * B[j] - C[j] * B[i]) / (A[i] * B[j] - A[j] * B[i]);
				double py = (C[i] * A[j] - C[j] * A[i]) / (B[i] * A[j] - B[j] * A[i]);
				
				// 檢查座標 (px, py) 是否滿足所有的 N 個條件
				// 相當於 C++ 的程式碼中的 check 函式
				boolean ret = true;
				for (int k = 1; k <= N; k++) {
					if (A[k] * px + B[k] * py > C[k]) ret = false;
				}
				if (ret == true) {
					Answer = Math.max(Answer, px + py);
				}
			}
		}
		
		// 輸出
		System.out.format("%.12f\n", Answer);
	}
}