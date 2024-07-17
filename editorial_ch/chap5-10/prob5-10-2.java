import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		
		// 求出答案
		long mod = 1000000007;
		long val = N * (N + 1) / 2;
		val %= mod;
		System.out.println(val * val % mod);
	}
}