// 在 C 語言中由於無法使用如程式碼 4.5.1 的 vector<int>，本程式碼以下面三個步驟建構圖的鄰接表。
// 步驟 1. 計算各頂點的次數 degree[i] 
// 步驟 2. 使用malloc動態確保各 G[i] 的記憶體
// 步驟 3. 分配被確保的 G[i] 的邊的方向

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
	
	// 向　G 追加邊的資訊（步驟 3.）
	for (i = 1; i <= N; i++) cnt[i] = 0;
	for (i = 1; i <= M; i++) {
		G[A[i]][cnt[A[i]]] = B[i];
		cnt[A[i]] += 1;
		G[B[i]][cnt[B[i]]] = A[i];
		cnt[B[i]] += 1;
	}
	
	// 輸出
	for (i = 1; i <= N; i++) {
		printf("%d: {", i);
		for (j = 0; j < degree[i]; j++) {
			if (j >= 1) printf(","); // 以逗號為區隔來輸出
			printf("%d", G[i][j]); // G[i][j] 是與頂點　i 相鄰頂點之中的第　j 個頂點
		}
		printf("}\n");
	}
	
	// 刪除鄰接表 G
	for (i = 1; i <= N; i++) {
		free(G[i]);
	}
	
	return 0;
}
