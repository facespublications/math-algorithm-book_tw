import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		double X1 = sc.nextDouble();
		double Y1 = sc.nextDouble();
		double R1 = sc.nextDouble();
		double X2 = sc.nextDouble();
		double Y2 = sc.nextDouble();
		double R2 = sc.nextDouble();
		
		// 求出圓心之間的距離
		double D = Math.sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
		
		// 輸出答案
		if (D < Math.abs(R1 - R2)) {
			System.out.println("1");
		}
		else if (D == Math.abs(R1 - R2)) {
			System.out.println("2");
		}
		else if (D < R1 + R2) {
			System.out.println("3");
		}
		else if (D == R1 + R2) {
			System.out.println("4");
		}
		else {
			System.out.println("5");
		}
	}
}