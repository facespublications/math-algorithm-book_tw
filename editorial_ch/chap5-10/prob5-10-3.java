import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long C = sc.nextLong();
		
		// 計算
		long mod = 998244353;
		long D = A * (A + 1) / 2; D %= mod;
		long E = B * (B + 1) / 2; E %= mod;
		long F = C * (C + 1) / 2; F %= mod;
		
		// 輸出答案
		// 即使在此計算 (D * E * F) % mod ，可能在途中處理到 10^27 
		// 因此，注意即使是 long long 型態也會發生溢出！
		System.out.println((D * E % mod) * F % mod);
	}
}