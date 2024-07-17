import java.util.*;
 
class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cnt = 0;
		double LIMIT = 23; // 將此設為 30 的話，答案即為所求
		double Current = 0;
		
		// 1 個 1 個相加
		while (Current < LIMIT) {
			cnt += 1;
			Current += 1.0 / cnt;
		}
		
		// 輸出
		System.out.println(cnt);
	}
}
