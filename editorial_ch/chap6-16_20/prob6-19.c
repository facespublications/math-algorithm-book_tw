#include <stdio.h>

int N, B[109];

int main() {
	// 輸入
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N - 1; i++) {
		scanf("%d", &B[i]);
	}

	// 求出數列 A 的元素總和
	int answer = B[1] + B[N - 1];
	for (i = 2; i <= N - 1; i++) {
		answer += (B[i - 1] < B[i] ? B[i - 1] : B[i]);
	}

	// 輸出答案
	printf("%d\n", answer);

	return 0;
}