import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 輸入
		int N = sc.nextInt();
		long[] A = new long[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextLong();
		
		// 求出答案
		long R = LCM(A[1], A[2]);
		for (int i = 3; i <= N; i++) {
			R = LCM(R, A[i]);
		}
		
		// 輸出
		System.out.println(R);
	}
	static long GCD(long A, long B) {
		// 傳回最大公因數的函式
		while (A >= 1 && B >= 1) {
			if (A < B) {
				B %= A;
			}
			else {
				A %= B;
			}
		}
		if (A >= 1) {
			return A;
		}
		return B;
	}
	static long LCM(long A, long B) {
		// 傳回最小公倍數的函式
		return (A / GCD(A, B)) * B;
	}
}