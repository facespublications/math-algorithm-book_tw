import java.util.*;

class Code_3_05_1 {
	public static void main(String[] args) {
		Random rd = new Random();
		int N = 10000; // N 為測試次數（可適當變更）
		int M = 0;
		for (int i = 1; i <= N; i++) {
			double px = rd.nextDouble(); // 生成 0 以上 1 未滿的亂數（雖然C++ 的程式碼 3.5.1 為生成 0 以上 1 以下的亂數，但幾乎相同）
			double py = rd.nextDouble(); // 生成 0 以上 1 未滿的亂數（雖然C++ 的程式碼 3.5.1 為生成 0 以上 1 以下的亂數，但幾乎相同）
			// 與原點的距離為 sqrt(px * px + py * py)
			// 此值最好在1 以下，因此條件為「px * px + py * py <= 1」（與「sqrt(px * px + py * py) <= 1」同値）
			if (px * px + py * py <= 1.0) {
				M++;
			}
		}
		System.out.format("%.12f\n", 4.0 * M / N);
	}
}
