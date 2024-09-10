#include <iostream>
#include <algorithm>
using namespace std;

int N, L[2009], R[2009];
int Current_Time = 0, Answer = 0; // Current_Time為現在時間（之前看完的電影的結束時間）

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i];

	// 模擬電影的選擇方法
	// 可觀看電影的結束時間最小值min_endtime 最初是設定成像1000000 這樣不可能的值
	while (true) {
		int min_endtime = 1000000;
		for (int i = 1; i <= N; i++) {
			if (L[i] < Current_Time) continue;
			min_endtime = min(min_endtime, R[i]);
		}
		if (min_endtime == 1000000) break;
		Current_Time = min_endtime;
		Answer += 1;
	}

	// 輸出答案
	cout << Answer << endl;
	return 0;
}
