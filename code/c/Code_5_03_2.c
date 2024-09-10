#include <stdio.h>

int main() {
	// 輸入
	int N, K, A[59];
	scanf("%d%d", &N, &K);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	// 求數列元素的總和sum
	int sum = 0;
	for (i = 1; i <= N; i++) {
		sum += A[i];
	}

	// 輸出答案
	if (sum % 2 != K % 2) {
		printf("No\n");
	}
	else if (sum > K) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	return 0;
}
