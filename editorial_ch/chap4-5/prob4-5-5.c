#include <stdio.h>
#include <stdlib.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];

int main() {
	// 輸入
	scanf("%d%d", &N, &M);
	int i, j;
	for (i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}
	
	// 製作鄰接表（參照 ~/codes/c/Code_4_5_1.c）
	for (i = 1; i <= N; i++) degree[i] = 0;
	for (i = 1; i <= M; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	for (i = 1; i <= N; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	for (i = 1; i <= N; i++) cnt[i] = 0;
	for (i = 1; i <= M; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// 求出答案
	int answer = 0;
	for (i = 1; i <= N; i++) {
		int cnt = 0;
		for (j = 0; j < degree[i]; j++) {
			// G[i][j] 是與頂點 i 鄰接的頂點中第 j+1 個
			if (G[i][j] < i) {
				cnt += 1;
			}
		}
		// 如果比自己的編號小的鄰接頂點為 1 個的話，將 Answer 加 1
		if (cnt == 1) {
			answer += 1;
		}
	}
	
	// 輸出答案
	printf("%d\n", answer);
	
	return 0;
}
