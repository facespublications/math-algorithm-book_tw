import java.util.*;

class Code_2_02_2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt(); // 輸入 a
		int b = sc.nextInt(); // 輸入 b
		System.out.println(a & b); // 輸出 a AND b的值
		System.out.println(a | b); // 輸出 a OR b的值
		System.out.println(a ^ b); // 輸出 a XOR b的值
	}
};
