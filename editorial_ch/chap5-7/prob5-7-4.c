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

long long N;
long long X[200009], Y[200009];

int main() {
	// 輸入
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld%lld", &X[i], &Y[i]);
	
	// 將陣列排序
	qsort(X + 1, N, sizeof(long long), compare_values);
	qsort(Y + 1, N, sizeof(long long), compare_values);
	
	// 部分 1 的答案（x 座標的差的絕對值總和）
	long long Part1 = 0;
	for (int i = 1; i <= N; i++) Part1 += X[i] * (-N + 2LL * i - 1LL);
	
	// 部分 2 的答案（y 座標的差的絕對值總和）
	long long Part2 = 0;
	for (int i = 1; i <= N; i++) Part2 += Y[i] * (-N + 2LL * i - 1LL);
	
	// 輸出
	printf("%lld\n", Part1 + Part2);
	return 0;
}