#include <stdio.h>

int main() {
	// 輸入
	int N, A[109];
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	
	// 對5 張卡片的編號(i, j, k, l, m) 進行全搜尋
	int answer = 0;
	int i, j, k, l, m;
	for (i = 1; i <= N; i++) {
		for (j = i + 1; j <= N; j++) {
			for (k = j + 1; k <= N; k++) {
				for (l = k + 1; l <= N; l++) {
					for (m = l + 1; m <= N; m++) {
						if (A[i] + A[j] + A[k] + A[l] + A[m] == 1000) {
							answer += 1;
						}
					}
				}
			}
		}
	}
	
	// 答案的輸出
	printf("%d\n", answer);
	return 0;
}
