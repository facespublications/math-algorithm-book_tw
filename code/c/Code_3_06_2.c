#include <stdio.h>

int N, A[200009];

int main() {
	// 輸入
	scanf("%d", &N);
	int i, j;
	for (i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	// 選擇排序
	for (i = 1; i <= N - 1; i++) {
		int min_position = i;
		int min_value = A[i];
		for (j = i + 1; j <= N; j++) {
			if (A[j] < min_value) {
				min_position = j; // min_position 為最小值的索引（1 ∼ N）
				min_value = A[j]; // min_value 為當下的最小值
			}
		}
		// 透過下面３行交換 A[i] 與 A[min_position]
		int temp = A[i];
		A[i] = A[min_position];
		A[min_position] = temp;
	}

	// 輸出
	for (int i = 1; i <= N; i++) {
		printf("%d\n", A[i]);
	}
	return 0;
}
