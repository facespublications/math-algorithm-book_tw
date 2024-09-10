#include <stdio.h>

int main() {
	// 輸入
	int N, X, Y;
	scanf("%d%d%d", &N, &X, &Y);
	
	// 求解
	int cnt = 0;
	int i;
	for (i = 1; i <= N; i++) {
		// mod 的計算參照第2.2節
		if (i % X == 0 || i % Y == 0) {
			cnt += 1;
		}
	}
	
	// 輸出
	printf("%d\n", cnt);
	
	return 0;
}
