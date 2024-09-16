import java.util.*;

class Code_5_06_1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int answer = 0;
		for (int i = 1; i <= B; i++) {
			if (shouMondai(A, B, i) == true) {
				answer = i;
			}
		}
		System.out.println(answer);
	}
	static boolean shouMondai(int A, int B, int t) {
		// 求解小問題 t 的函式
		int cl = (A + t - 1) / t; // 將 A÷t 的小數點以下進位
		int cr = B / t; // 將　B÷t 的小數點以下捨去
		return (cr - cl >= 1); // 若 cr - cl >= 1 則 true，否則回傳 false
	}
}
