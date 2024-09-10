#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	char answer[100] = ""; // 以char型的陣列表示字串
	while (N >= 1) {
		// N % 2 為 N 除以 2 的餘數（例如：N=13 時為1）
		// N / 2 為N 除以2 的值的整數部分（例如：N=13 時為6）
		char next_answer[101];
		if (N % 2 == 0) {
			// next_answer 代入「連結 "0" 和 answer 的東西」
			sprintf(next_answer, "0%s", answer);
		}
		if (N % 2 == 1) {
			// next_answer 代入「連結 "1" 和 answer 的東西」
			sprintf(next_answer, "1%s", answer);
		}
		strcpy(answer, next_answer);
		N = N / 2;
	}
	printf("%s\n", answer);
	return 0;
}
