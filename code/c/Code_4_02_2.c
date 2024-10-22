#include <stdio.h>

int N, B[100009];
int Q, L[100009], R[100009], X[100009];

int main() {
	// 輸入
	scanf("%d%d", &N, &Q);
	int i;
	for (i = 1; i <= Q; i++) {
		scanf("%d%d%d", &L[i], &R[i], &X[i]);
	}
	
	// 階差的計算
	for (i = 1; i <= Q; i++) {
		B[L[i]] += X[i];
		B[R[i] + 1] -= X[i];
	}

	// 輸出答案
	for (i = 2; i <= N; i++) {
		if (B[i] > 0) printf("<");
		if (B[i] == 0) printf("=");
		if (B[i] < 0) printf(">");
	}
	printf("\n");
	return 0;
}
