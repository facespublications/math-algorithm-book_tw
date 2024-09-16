import java.util.*;

class Code_5_09_1 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 支付方式的模擬
		long answer = 0;
		while (N >= 10000) {
			N -= 10000; // 10000 圓以上則繼續使用 10000 圓紙鈔
			answer += 1;
		}
		while (N >= 5000) {
			N -= 5000; // 5000 圓以上則繼續使用 5000 圓紙鈔
			answer += 1;
		}
		while (N >= 1) {
			N -= 1000; // 剩餘金額使用 1000 圓紙鈔支付
			answer += 1;
		}
		
		// 輸出答案
		System.out.println(answer);
	}
}
