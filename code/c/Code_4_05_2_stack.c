// 這個原始碼為將深度優先搜尋 (DFS) 使用了堆疊的實作例。
// 堆疊為可進行「在最上層堆積元素」、「查找堆積在最上層的元素」、「刪除堆積在最上層的元素」三種操作的資料結構。
// 深度優先搜尋的部分為將程式碼 4.5.3 的 queue 變更為 stack，以此為基礎撰寫。
// 鄰接表的做法請參考程式碼 4.5.1 的註解。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];
bool visited[100009];

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
	
	// 建構鄰接表 G （步驟 2.）
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
	
	
	// 定義堆疊 S 
	// 讓堆疊的內容變成 S[0], S[1], ..., S[SZ - 1] 
	int S[100009], SZ = 0;
	
	// 深度優先搜尋的初始化
	for (i = 1; i <= N; i++) {
		visited[i] = false;
	}
	visited[1] = true;
	S[SZ] = 1; SZ++; // S 追加 1
	
	// 廣度優先搜尋
	while (SZ >= 1) {
		int pos = S[SZ - 1]; // 調查 S 的開頭
		SZ--; // 取出 S 的開頭
		for (i = 0; i < degree[pos]; i++) {
			int nex = G[pos][i];
			if (visited[nex] == false) {
				visited[nex] = true;
				S[SZ] = nex; SZ++; // 追加 nex 至 S
			}
		}
	}
	
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
