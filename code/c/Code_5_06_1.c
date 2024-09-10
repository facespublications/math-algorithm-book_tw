#include <stdio.h>
#include <stdbool.h>

// 求解小問題 t 的函式
bool shou_mondai(int A, int B, int t) {
	int cl = (A + t - 1) / t; // 將 A÷t 的小數點以下進位
	int cr = B / t; // 將B÷t 的小數點以下捨去
	if (cr - cl >= 1) return true;
	return false;
}

int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	int answer = 0;
	int i;
	for (i = 1; i <= B; i++) {
		if (shou_mondai(A, B, i) == true) {
			answer = i;
		}
	}
	printf("%d\n", answer);
	return 0;
}
