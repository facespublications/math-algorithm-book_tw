import java.util.*;

class Main {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long B = sc.nextLong();
		
		// 列舉各個位數乘積的候選
		func(0, 0);
		
		// 檢查是否為 m - f(m) == B
		long Answer = 0;
		for (long fm : fm_cand) {
			long m = fm + B;
			long prod_m = product(m);
			if (m - prod_m == B && m <= N) {
				Answer += 1;
			}
		}
		
		// 輸出
		System.out.println(Answer);
	}
	
	static Set<Long> fm_cand = new TreeSet<Long>();
	
	static void func(int digit, long m) {
		// 位數為 11 位時，可以中止
		// 注：如果用 1 填充剩餘的位數，可以假設全部都是 11 位。
		if (digit == 11) {
			fm_cand.add(product(m));
			return;
		}
		
		// 搜尋下一位
		// min_value 為 cur 的最後一位（為了使其單調遞增，下一位必須為比它大的值）
		int min_value = (int)(m % 10);
		for (int i = min_value; i <= 9; i++) {
			func(digit + 1, 10L * m + 1L * i);
		}
	}
	
	// 回傳 m 的各個位數乘積的函式
	static long product(long m) {
		// m = 0 
		if (m == 0) {
			return 0;
		}
		else {
			long ans = 1;
			while (m >= 1) {
				ans *= (m % 10);
				m /= 10;
			}
			return ans;
		}
	}
}