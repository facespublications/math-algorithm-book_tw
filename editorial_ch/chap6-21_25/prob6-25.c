#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];

bool visited[100009];
int dp[100009];
void dfs(int pos) {
	visited[pos] = true;
	dp[pos] = 1;
	int i;
	for (i = 0; i < degree[pos]; i++) {
		if (visited[G[pos][i]] == false) {
			dfs(G[pos][i]);
			dp[pos] += dp[G[pos][i]];
		}
	}
}

int main() {
	// 輸入
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N - 1; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}
	
	// 製作鄰接表（參照 ~/codes/c/Code_4_5_1.c）
	for (i = 1; i <= N; i++) degree[i] = 0;
	for (i = 1; i <= N - 1; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	for (i = 1; i <= N; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	for (i = 1; i <= N; i++) cnt[i] = 0;
	for (i = 1; i <= N - 1; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// 使用深度優先搜尋 (DFS) 的動態規劃法
	for (i = 1; i <= N; i++) {
		visited[i] = false;
	}
	dfs(1);
	
	// 計算答案並輸出
	long long answer = 0;
	for (i = 2; i <= N; i++) {
		answer += 1LL * dp[i] * (N - dp[i]);
	}
	printf("%lld\n", answer);
	
	return 0;
}