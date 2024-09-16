import java.util.*;

class Code_2_02_1 {
	public static void main(String[] args) {
		// 四則運算
		System.out.println(869 + 120); // 輸出 989
		System.out.println(869 - 120); // 輸出 749
		System.out.println(869 * 120); // 輸出 104280
		System.out.println(869 / 120); // 輸出 7 （注意在此只輸出整數部分）
		
		// 餘數 (mod)
		System.out.println(8 % 5); // 輸出 3
		System.out.println(869 % 120); // 輸出 29
		
		// 絕對值 (abs)
		System.out.println(Math.abs(-45)); // 輸出 45
		System.out.println(Math.abs(15)); // 輸出 15
		
		// 乘方 (pow)
		System.out.println((int)Math.pow(10.0, 2.0)); // 輸出 100
		System.out.println((int)Math.pow(3.0, 4.0)); // 輸出 81
		
		// 方根 (sqrt)
		System.out.format("%.5f\n", Math.sqrt(4.0)); // 輸出 2.00000
		System.out.format("%.5f\n", Math.sqrt(2.0)); // 輸出 1.41421
	}
};
