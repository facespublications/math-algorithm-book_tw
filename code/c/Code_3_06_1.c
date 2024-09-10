#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// a 先出現時為負值
	// b 先出現時為正值
	// a 與 b 為相同值時返回 0 的函數
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a > *(int*)b) return +1;
	return 0;
}

int N, A[200009];

int main() {
	// 輸入（例如輸入了N=5、A[1]=3、A[2]=1、A[3]=4、A[4]=1,A[5]=5）
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	// 排序（因為要排序從　A[1] 開始的N個元素，因此引數指定　A+1, N）
	// 藉由 qsort 函式，將陣列的內容[3,1,4,1,5] 改寫為1,1,3,4,5]
	qsort(A + 1, N, sizeof(int), compare_values);
	
	// 輸出（按照1、1、3、4、5 的順序輸出）
	for (i = 1; i <= N; i++) {
		printf("%d\n", A[i]);
	}
	
	return 0;
}
