#include <iostream>
using namespace std;

int main() {
	// 輸入
	int N, X, Y;
	cin >> N >> X >> Y;

	// 求解
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i % X == 0 || i % Y == 0) cnt++; // mod 的計算請參考 2.2 節
	}

	// 輸出
	cout << cnt << endl;
	return 0;
}
