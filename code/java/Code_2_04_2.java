import java.util.*;

class Code_2_04_2 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		// 求解
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			// mod 的計算請參考 2.2 節
			if (i % X == 0 || i % Y == 0) {
				cnt++;
			}
		}
		
		// 輸出
		System.out.println(cnt);
	}
}
