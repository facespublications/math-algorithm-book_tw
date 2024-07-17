import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		
		// 嘗試所有 (a, b, c) 的組合
		int answer = 0;
		for (int a = 1; a <= N; a++) {
			for (int b = a + 1; b <= N; b++) {
				for (int c = b + 1; c <= N; c++) {
					if (a + b + c == X) {
						answer += 1;
					}
				}
			}
		}
		
		// 輸出答案
		System.out.println(answer);
	}
}