import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 輸入
		long N = sc.nextLong();
		
		// 質因數分解、輸出（以空白來區隔）
		boolean flag = false;
		for (long i = 2; i * i <= N; i++) {
			while (N % i == 0) {
				if (flag == true) System.out.print(" ");
				flag = true;
				N /= i;
				System.out.print(i);
			}
		}
		
		// 最後剩下的 N
		if (N >= 2) {
			if (flag == true) System.out.print(" ");
			flag = true;
			System.out.print(N);
		}
		System.out.println();
	}
}