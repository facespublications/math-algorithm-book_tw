#include <stdio.h>
 
int compare_values(const void* a, const void* b) {
	// 當 a 在前面時 回傳負值
	// 當 b 在前面時 回傳正值
	// 當 a 與 b 為相等的值時回傳 0 的函式
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a > *(int*)b) return +1;
	return 0;
}

long long N;
long long A[100009], B[100009];
 
int main() {
	// 輸入
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; i++) scanf("%lld", &B[i]);
	
	// 排序
	qsort(A + 1, N, sizeof(long long), compare_values);
	qsort(B + 1, N, sizeof(long long), compare_values);
	
	// 求出答案
	long long Answer = 0;
	for (int i = 1; i <= N; i++) {
		if (A[i] >= B[i]) Answer += (A[i] - B[i]);
		else Answer += (B[i] - A[i]);
	}
	printf("%lld\n", Answer);
	return 0;
}