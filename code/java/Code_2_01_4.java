import java.util.*;

class Code_2_01_4 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(); // 輸入部分
		String answer = ""; // String 為字串型別
		while (N >= 1) {
			// N % 2 為 N 除以 2 的餘數（例如：N=13 時為1）
			// N / 2 為 N 除以 2 的值的整數部分（例如：N=13 時為6）
			if (N % 2 == 0) {
				answer = "0" + answer;
			}
			if (N % 2 == 1) {
				answer = "1" + answer;
			}
			N = N / 2;
		}
		System.out.println(answer); // 輸出部分
	}
};
