import java.util.*;

class Main {
	public static void MergeSort(int[] A, int[] C, int l, int r) {
		// r−l=1 時，因為已經被排序完成，所以什麼都不用做
		if (r - l == 1) return;
		
		// 分割成 2 個之後，將較小的陣列排序
		int m = (l + r) / 2;
		MergeSort(A, C, l, m);
		MergeSort(A, C, m, r);
		
		// 此時，以下 2 個陣列已被排序：
		// 相當於列 A' 的 [A[l], A[l+1], ..., A[m−1]]
		// 相當於列 B' 的 [A[m], A[m+1], ..., A[r−1]]
		// 以下為 Merge 操作。
		int c1 = l, c2 = m, cnt = 0;
		while (c1 != m || c2 != r) {
			if (c1 == m) {
				// 列 A' 為空時
				C[cnt] = A[c2]; c2++;
			}
			else if (c2 == r) {
				// 列 B' 為空時（缺少的部分）
				C[cnt] = A[c1]; c1++;
			}
			else {
				// 兩者都不是時
				if (A[c1] <= A[c2]) {
					C[cnt] = A[c1]; c1++;
				}
				else {
					C[cnt] = A[c2]; c2++;
				}
			}
			cnt++;
		}
		
		// 將合併了列 A'、列 B' 的陣列 C 移到 A
		// [C[0], C[1], ..., C[cnt-1]] -> [A[l], A[l+1], ..., A[r-1]]
		for (int i = 0; i < cnt; i++) A[l + i] = C[i];
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 輸入
		int N = sc.nextInt();
		int[] A = new int[N + 1];
		int[] C = new int[N + 1];
		for (int i = 1; i <= N; i++) A[i] = sc.nextInt();
		
		// 合併排序
		MergeSort(A, C, 1, N + 1);
		
		// 輸出
		for (int i = 1; i <= N; i++) {
			System.out.println(A[i]);
		}
	}
}