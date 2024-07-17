import java.util.*;

class Main {
	public static void main(String[] args) {
		double r = 2.0; // 因為想求 √2
		double a = 2.0; // 將初始值隨意的設為 2.0
		for (int i = 1; i <= 5; i++) {
			// 求點 (a, f(a)) 的 x 座標與 y 座標
			double zahyou_x = a;
			double zahyou_y = a * a * a;
			
			// 求切線的式子 y = sessen_a * x + sessen_b
			double sessen_a = 3.0 * zahyou_x * zahyou_x;
			double sessen_b = zahyou_y - sessen_a * zahyou_x;
			
			// 求下一個 a 的值 next_a
			double next_a = (r - sessen_b) / sessen_a;
			System.out.format("Step #%d: a = %.12f -> %.12f\n", i, a, next_a);
			a = next_a;
		}
	}
}