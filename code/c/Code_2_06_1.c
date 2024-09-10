#include <stdio.h>

int main() {
	// 輸入
	long long N, S, A[61];
	scanf("%lld%lld", &N, &S);
	long long i, j;
	for (i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}
	
	// 搜尋全部模式：（1LL << N）為 2 的N 次方
	for (i = 0; i < (1LL << N); i++) {
		long long sum = 0;
		for (j = 1; j <= N; j++) {
			// (i & (1LL << (j-1))) != 0LL 時，i 的二進制表示的倒數第j 位是1
			// (1LL << (j-1)) 在C++ 中代表「2 的j-1 次方」
			if ((i & (1LL << (j - 1))) != 0LL) {
				sum += A[j];
			}
		}
		if (sum == S) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
