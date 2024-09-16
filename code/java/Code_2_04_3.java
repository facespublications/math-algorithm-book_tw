import java.util.*;

class Code_2_04_3 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int S = sc.nextInt();
		
		// 求解
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i + j <= S) {
					cnt++;
				}
			}
		}
		
		// 輸出
		System.out.println(cnt);
	}
}
