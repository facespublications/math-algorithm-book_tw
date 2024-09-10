#include <stdio.h>
#include <stdbool.h>

int N; bool prime[100000009];

int main() {
	// 輸入→陣列的初始化
	scanf("%d", &N);
	int i, x;
	for (i = 2; i <= N; i++) {
		prime[i] = true;
	}

	// 埃拉托斯特尼篩
	for (i = 2; i * i <= N; i++) {
		if (prime[i] == true) {
			for (x = 2 * i; x <= N; x += i) {
				prime[x] = false;
			}
		}
	}

	// 將 N 以下的質數以從小到大的順序輸出
	for (i = 2; i <= N; i++) {
		if (prime[i] == true) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
