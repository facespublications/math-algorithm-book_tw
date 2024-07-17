#include <stdio.h>
#include <stdlib.h>

int H, W, sx, sy, gx, gy, start, goal; char c[59][59];

int edges, A[5009], B[5009], degree[2509], cnt[2509];
int* G[2509];
int dist[2509];

int main() {
	// 輸入
	scanf("%d%d", &H, &W);
	scanf("%d%d", &sx, &sy);
	scanf("%d%d", &gx, &gy);
	int i, j;
	for (i = 1; i <= H; i++) {
		scanf("%s", c[i] + 1); // 將輸入的字串儲存於 c[i][1], c[i][2], ... （1 開始的索引）
	}
	start = (sx - 1) * W + sy;
	goal = (gx - 1) * W + gy;
	
	// 將圖的邊列表（edges 為現在的邊的數量）
	edges = 0;
	for (i = 1; i <= H; i++) {
		for (j = 1; j <= W - 1; j++) {
			if (c[i][j] == '.' && c[i][j + 1] == '.') {
				edges += 1;
				A[edges] = (i - 1) * W + j; // 方格 (i, j) 的頂點編號
				B[edges] = (i - 1) * W + (j + 1); // 方格 (i, j + 1) 的頂點編號
			}
		}
	}
	for (i = 1; i <= H - 1; i++) {
		for (j = 1; j <= W; j++) {
			if (c[i][j] == '.' && c[i + 1][j] == '.') {
				edges += 1;
				A[edges] = (i - 1) * W + j; // マス (i, j) 的頂點編號
				B[edges] = i * W + j; // 方格 (i + 1, j) 的頂點編號
			}
		}
	}
	
	// 製作鄰接表（參照 ~/codes/c/Code_4_5_1.c）
	for (i = 1; i <= H * W; i++) degree[i] = 0;
	for (i = 1; i <= edges; i++) {
		degree[A[i]] += 1;
		degree[B[i]] += 1;
	}
	for (i = 1; i <= H * W; i++) {
		G[i] = (int*)malloc(degree[i] * sizeof(int));
	}
	for (i = 1; i <= H * W; i++) cnt[i] = 0;
	for (i = 1; i <= edges; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// 佇列 Q 的定義 → 廣度優先搜尋的初始化（參照 ~/codes/c/Code_4_5_3.c）
	int Q[2509];
	int QL = 0, QR = 0;
	for (i = 1; i <= H * W; i++) {
		dist[i] = -1;
	}
	dist[start] = 0;
	Q[QR] = start; QR++; // 於 Q 添加 start 
	
	// 廣度優先搜尋（參照 ~/codes/c/Code_4_5_3.c）
	while (QL != QR) {
		int pos = Q[QL]; // 查看 Q 的開頭
		QL++; // 取出 Q 的開頭
		for (i = 0; i < degree[pos]; i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q[QR] = nex; QR++; // 於 Q 添加 nex
			}
		}
	}
	
	// 輸出答案
	printf("%d\n", dist[goal]);
	
	return 0;
}
