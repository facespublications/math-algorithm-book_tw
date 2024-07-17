import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String C = sc.next();
		
		// 求出答案
		int answer = 0;
		for (int i = 0; i < N; i++) {
			int code = -1;
			if (C.charAt(i) == 'B') code = 0;
			if (C.charAt(i) == 'W') code = 1;
			if (C.charAt(i) == 'R') code = 2;
			answer += code * ncr(N - 1, i);
			answer %= 3;
		}
		
		// 將答案乘以 (-1)^(N-1) 
		if (N % 2 == 0) {
			answer = (3 - answer) % 3;
		}
		
		// 輸出答案（"BWR" 的第 answer 個字母）
		System.out.println("BWR".charAt(answer));
	}
	
	// 用盧卡斯定理計算 ncr mod 3
	static int ncr(int x, int y) {
		if (x < 3 && y < 3) {
			if (x < y) return 0;
			if (x == 2 && y == 1) return 2;
			return 1;
		}
		return ncr(x / 3, y / 3) * ncr(x % 3, y % 3) % 3;
	}
}