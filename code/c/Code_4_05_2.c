// 鄰接表的做法請參考程式碼 4.5.1 的comment

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];

bool visited[100009];

void dfs(int pos) {
	visited[pos] = true;
	int i;
	for (i = 0; i < degree[pos]; i++) {
		if (visited[G[pos][i]] == false) {
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
	
	// 計算各頂點的次數（步驟 1.）
	for (i = 1; i <= N; i++) degree[i] = 0;
	for (i = 1; i <= M; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	
	// 構築鄰接表 G （步驟 2.）
	for (i = 1; i <= N; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	
	// 向 G 追加邊的資訊（步驟 3.）
	for (i = 1; i <= N; i++) cnt[i] = 0;
	for (i = 1; i <= M; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// 深度優先搜尋
	for (i = 1; i <= N; i++) {
		visited[i] = false;
	}
	dfs(1);
	
	// 判定是否連通（Answer=true 時為連通）
	bool answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			answer = false;
		}
	}
	if (answer == true) {
		printf("The graph is connected.\n");
	}
	else {
		printf("The graph is not connected.\n");
	}
	
	// 刪除鄰接表 G 
	for (i = 1; i <= N; i++) {
		free(G[i]);
	}
	
	return 0;
}
