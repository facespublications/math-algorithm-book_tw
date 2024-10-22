import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 輸入
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		
		// 求出答案
		long x = 0, y = 0, z = 0;
		for (int i = 1; i <= N; i++) {
			if (A[i] == 1) x += 1;
			if (A[i] == 2) y += 1;
			if (A[i] == 3) z += 1;
		}
		
		// 輸出
		System.out.println(x * (x - 1) / 2 + y * (y - 1) / 2 + z * (z - 1) / 2);
	}
}