import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] A = new int[N][2];
		for (int i = 1; i <= N; i++) {
			A[i - 1][0] = sc.nextInt();
			A[i - 1][1] = sc.nextInt();
		}
		
		// 將陣列 A 以結束時間（A[x][1]）的遞增順序排序
		Arrays.sort(A, (a1, a2) -> Integer.compare(a1[1], a2[1]));
		
		// 持續選擇結束時間最早的電影
		int CurrentTime = 0;
		int Answer = 0;
		for (int i = 1; i <= N; i++) {
			if (CurrentTime <= A[i - 1][0]) {
				CurrentTime = A[i - 1][1];
				Answer += 1;
			}
		}
		
		// 輸出
		System.out.println(Answer);
	}
}