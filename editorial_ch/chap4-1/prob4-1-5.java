import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 輸入
		long X1 = sc.nextLong(); long Y1 = sc.nextLong();
		long X2 = sc.nextLong(); long Y2 = sc.nextLong();
		long X3 = sc.nextLong(); long Y3 = sc.nextLong();
		long X4 = sc.nextLong(); long Y4 = sc.nextLong();
		
		// 計算 cross 的值
		long ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
		long ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
		long ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
		long ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);
		
		// 全部排在一直線上時（邊角案例）
		// 因為無法使用　pair 型態，與　C++ 的實作方法會稍有差異
		if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
			if (X1 == X2 && X2 == X3 && X3 == X4) {
				long a = Y1, b = Y2;
				if (a > b) { // swap(a, b)
					long tmp = b;
					b = a;
					a = tmp;
				}
				long c = Y3, d = Y4;
				if (c > d) { // swap(c, d)
					long tmp = d;
					d = c;
					c = tmp;
				}
				if (Math.max(a, c) <= Math.min(b, d)) {
					System.out.println("Yes");
				}
				else {
					System.out.println("No");
				}
			}
			else {
				long a = X1, b = X2;
				if (a > b) { // swap(a, b)
					long tmp = b;
					b = a;
					a = tmp;
				}
				long c = X3, d = X4;
				if (c > d) { // swap(c, d)
					long tmp = d;
					d = c;
					c = tmp;
				}
				if (Math.max(a, c) <= Math.min(b, d)) {
					System.out.println("Yes");
				}
				else {
					System.out.println("No");
				}
			}
		}
		
		// 並非如此的普通狀況
		else {
			// IsAB: 線段 AB 是否將點 C, D 分開？
			// IsCD: 線段 CD 是否將點 A, B 分開？
			boolean IsAB = false, IsCD = false;
			if (ans1 >= 0 && ans2 <= 0) IsAB = true;
			if (ans1 <= 0 && ans2 >= 0) IsAB = true;
			if (ans3 >= 0 && ans4 <= 0) IsCD = true;
			if (ans3 <= 0 && ans4 >= 0) IsCD = true;
			
			// 輸出答案
			if (IsAB == true && IsCD == true) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
	}
	static long cross(long ax, long ay, long bx, long by) {
		return ax * by - ay * bx;
	}
};