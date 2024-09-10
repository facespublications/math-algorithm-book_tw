#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// 比較 2 個 long long 型的值的函數（參考 Code_3_06_1.c）
	if (*(long long*)a < *(long long*)b) return -1;
	if (*(long long*)a > *(long long*)b) return +1;
	return 0;
}

int N; long long X, A[1000009];

int main() {
	// 輸入
	scanf("%d%lld", &N, &X);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	// 陣列的排序（參考 Code_3_06_1.c）
	qsort(A + 1, N, sizeof(long long), compare_values);

	// 二元搜尋
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right) / 2; // 以搜尋範圍的中央進行分割
		if (A[mid] == X) {
			printf("Yes\n");
			return 0;
		}
		if (A[mid] > X) right = mid - 1; // 將搜尋範圍縮小到前半部分
		if (A[mid] < X) left = mid + 1; // 將搜尋範圍縮小到後半部分
	}

	// 當搜尋範圍耗盡仍非Yes 時，答案即為No
	printf("No\n");
	return 0;
}
