import java.util.*;

class Code_5_10_4 {
	public static void main(String[] args) {
		// 輸入
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		
		// 令'(' 的數量-')' 的數量為depth
		// 如果 depth 在過程中變為負的話，此時為 No
		int depth = 0;
		boolean flag = true;
		for (int i = 0; i < N; i++) {
			if (S.charAt(i) == '(') {
				depth += 1;
			}
			if (S.charAt(i) == ')') {
				depth -= 1;
			}
			if (depth < 0) {
				flag = false;
			}
		}
		
		// 最後，也追加判定是否 depth=0['(' 和')' 的數量相同] 
		if (flag == true && depth == 0) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
