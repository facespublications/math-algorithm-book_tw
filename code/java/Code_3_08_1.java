import java.util.*;

class Code_3_08_1 {
	public static void main(String[] args) {
		// 輸入（注意：此處按照陣列 A[0] 到 A[N-1] 的順序輸入。下標從零開始稱作 0-indexed 等。）
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long X = sc.nextLong();
		long[] A = new long[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextLong();
		}
		
		// 陣列的排序
		Arrays.sort(A);
		
		// 二元搜尋
		String answer = "No";
		int left = 0, right = N - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (A[mid] == X) {
				answer = "Yes";
				break;
			}
			if (A[mid] > X) {
				// 將搜尋範圍縮小到前半部分
				right = mid - 1;
			}
			if (A[mid] < X) {
				// 將搜尋範圍縮小到後半部分
				left = mid + 1;
			}
		}
		
		// 輸出答案
		System.out.println(answer);
	}
}
