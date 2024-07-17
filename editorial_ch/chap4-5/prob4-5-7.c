#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[200009], B[200009]; // N, M ≦ 200000 ，因此使陣列的大小為 200009 
int degree[200009], cnt[200009];
int* G[200009];

int color[200009];

void dfs(int pos) {
	int i;
	for (i = 0; i < degree[pos]; i++) {
		if (color[G[pos][i]] == 0) {
			// color[pos] = 1 的時候為 2，color[pos] = 2 的時候為 1
			color[G[pos][i]] = 3 - color[pos];
			dfs(G[pos][i]);
		}
	}
}

int main() {
	// 輸入
	scanf("%d%d", &N, &M);
	int i;
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
	
	// 深度優先搜尋
	for (i = 1; i <= N; i++) {
		color[i] = 0;
	}
	for (i = 1; i <= N; i++) {
		if (color[i] == 0) {
			// 頂點 i 為白（尚未搜尋的連通成分）
			color[i] = 1;
			dfs(i);
		}
	}
	
	// 是否為二部圖的判斷
	bool answer = true;
	for (i = 1; i <= M; i++) {
		if (color[A[i]] == color[B[i]]) {
			answer = false;
		}
	}
	if (answer == true) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	
	return 0;
}
