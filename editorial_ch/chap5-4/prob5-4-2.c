#include <stdio.h>
 
int H, W, A[2009][2009];
int gyou[2009]; // 列的總和
int retu[2009]; // 行的總和
int Answer[2009][2009];
 
int main() {
	// 輸入
	scanf("%d%d", &H, &W);
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) scanf("%d", &A[i][j]);
	}
	
	// 計算列的總和
	for (int i = 1; i <= H; i++) {
		gyou[i] = 0;
		for (int j = 1; j <= W; j++) gyou[i] += A[i][j];
	}
	
	// 計算行的總和
	for (int j = 1; j <= W; j++) {
		retu[j] = 0;
		for (int i = 1; i <= H; i++) retu[j] += A[i][j];
	}
	
	// 對各網格計算答案
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			Answer[i][j] = gyou[i] + retu[j] - A[i][j];
		}
	}
	
	// 以空格區隔來輸出
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (j >= 2) printf(" ");
			printf("%d", Answer[i][j]);
		}
		printf("\n");
	}
	return 0;
}