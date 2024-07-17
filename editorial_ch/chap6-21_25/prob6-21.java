import java.util.*;

class Main {
	public static void main(String[] args) {
		double r = 2.0; // 因為所求為 y = e^x 和 y = 2 的交點
		double a = 1.0; // 將初始值任意設定為 1.0
		for (int i = 1; i <= 5; i++) {
			// 求出點 (a, f(a)) 的 x 座標與 y 座標
			double zahyou_x = a;
			double zahyou_y = Math.exp(a);
			
			// 求出切線式 y = sessen_a * x + sessen_b
			double sessen_a = zahyou_y;
			double sessen_b = zahyou_y - sessen_a * zahyou_x;
			
			// 求出下個 a 的值 next_a 
			double next_a = (r - sessen_b) / sessen_a;
			System.out.format("Step #%d: a = %.15f -> %.15f\n", i, a, next_a);
			a = next_a;
		}
	}
}