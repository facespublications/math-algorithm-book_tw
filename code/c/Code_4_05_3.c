// 鄰接表的做法請參考程式碼 4.5.1 的註解。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M, A[100009], B[100009];
int degree[100009], cnt[100009];
int* G[100009];
int dist[100009];

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
	
	
	// 定義佇列 Q
	// 讓佇列 Q 的內容變成 Q[QL], Q[QL+1], ..., Q[QR-1] 
	// （詳細的原理請參照 https://qiita.com/square1001/items/6d414167ca95c97bd8b2 的第 5 節）
	int Q[100009];
	int QL = 0, QR = 0;
	
	// 廣度優先搜尋的初始化（dist[i]=-1 時，為未到達的白色頂點）
	for (i = 1; i <= N; i++) {
		dist[i] = -1;
	}
	dist[1] = 0;
	Q[QR] = 1; QR++; // 將 1 添加到 Q 中（操作 1）
	
	// 廣度優先搜尋
	while (QL != QR) {
		int pos = Q[QL]; // 查看 Q 的開頭（操作2）
		QL++; // 取出Q 的開頭（操作3）
		for (i = 0; i < degree[pos]; i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q[QR] = nex; QR++; // 將nex 添加到Q 中（操作1）
			}
		}
	}
	
	// 輸出從頂點1 到各頂點的最短距離
	for (i = 1; i <= N; i++) {
		printf("%d\n", dist[i]);
	}
	
	// 刪除鄰接表 G 
	for (i = 1; i <= N; i++) {
		free(G[i]);
	}
	
	return 0;
}
