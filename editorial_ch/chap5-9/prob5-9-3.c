#include <stdio.h>
 
// Movie 型態
struct Movie {
	int l, r;
};

// 將 r 較小者判定為「小」
int compare_values(const void* a, const void* b) {
	// 當 a 在前面時 回傳負值
	// 當 b 在前面時 回傳正值
	// 當 a 與 b 為相等的值時回傳 0 的函式
	struct Movie A = *(const struct Movie*)a;
	struct Movie B = *(const struct Movie*)b;
	if (A.r < B.r) return -1;
	else if (A.r > B.r) return +1;
	return 0;
}

int N;
struct Movie A[300009];
int CurrentTime = 0; // 現在時間（最後所選電影的結束時間）
int Answer = 0; // 現在已看過的電影數
 
int main() {
	// 輸入
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d%d", &A[i].l, &A[i].r);
	
	// 排序
	qsort(A + 1, N, sizeof(*A), compare_values);
	
	// 持續選擇結束時間最早的電影
	for (int i = 1; i <= N; i++) {
		if (CurrentTime <= A[i].l) {
			CurrentTime = A[i].r;
			Answer += 1;
		}
	}
	
	// 輸出
	printf("%d\n", Answer);
	return 0;
}