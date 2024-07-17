#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// 當 a 在前面時 回傳負值
	// 當 b 在前面時 回傳正值
	// 當 a 與 b 為相等的值時回傳 0 的函式
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a > *(int*)b) return +1;
	return 0;
}
 
long long N, A[200009];
long long Answer = 0;
 
int main() {
	// 輸入
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld\n", &A[i]);
	
	// 排序（從程式碼 5.7.1 唯一增加的部分）
	qsort(A + 1, N, sizeof(long long), compare_values);
	
	// 求出答案 → 輸出答案
	for (int i = 1; i <= N; i++) Answer += A[i] * (-N + 2LL * i - 1LL);
	printf("%lld\n", Answer);
	return 0;
}