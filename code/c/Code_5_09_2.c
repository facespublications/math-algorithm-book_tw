#include <stdio.h>
#include <stdbool.h>

int N, L[2009], R[2009];

int main() {
	// 輸入
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &L[i], &R[i]);
	}

	// 模擬電影的選擇方法
	// 可觀看電影的結束時間最小值min_endtime 最初是設定成像1000000 這樣不可能的值
	int answer = 0;
	int current_time = 0; // Current_Time為現在時間（之前看完的電影的結束時間）
	while (true) {
		int min_endtime = 1000000;
		for (int i = 1; i <= N; i++) {
			if (L[i] < current_time) {
				continue;
			}
			if (min_endtime > R[i]) {
				min_endtime = R[i];
			}
		}
		if (min_endtime == 1000000) {
			break;
		}
		current_time = min_endtime;
		answer += 1;
	}

	// 答えの出力
	printf("%d\n", answer);
	return 0;
}
