import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long H = sc.nextLong();
		long W = sc.nextLong();
		
		// 區分狀況
		if (H == 1 || W == 1) {
			System.out.println(1);
		}
		else {
			System.out.println((H * W + 1) / 2);
		}
	}
}