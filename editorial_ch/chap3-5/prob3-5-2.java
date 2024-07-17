import java.util.*;

class Main {
	public static void main(String[] args) {
		Random rd = new Random();
		int N = 1000000; // N 為執行次數（可適當變更）
		int M = 0;
		for (int i = 1; i <= N; i++) {
			double px = 6.0 * rd.nextDouble();
			double py = 9.0 * rd.nextDouble();
			
			// 與點 (3, 3) 之間的距離。若此值為 3 以下，則會被包含在半徑 3 的圓內。
			double dist_33 = Math.sqrt((px - 3.0) * (px - 3.0) + (py - 3.0) * (py - 3.0));
			
			// 與點 (3, 7) 之間的距離。若此值為 2 以下，則會被包含在半徑 2 的圓內。
			double dist_37 = Math.sqrt((px - 3.0) * (px - 3.0) + (py - 7.0) * (py - 7.0));
			
			if (dist_33 <= 3.0 || dist_37 <= 2.0) M += 1;
		}
		System.out.println(M);
	}
}