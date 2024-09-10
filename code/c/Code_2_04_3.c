#include <stdio.h>

int main() {
	// 輸入
	int N, S;
	scanf("%d%d", &N, &S);
	
	// 求解
	int answer = 0;
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i + j <= S) {
				answer += 1;
			}
		}
	}
	
	// 輸出
	printf("%d\n", answer);
}
