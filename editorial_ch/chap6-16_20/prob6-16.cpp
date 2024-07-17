#include <iostream>
using namespace std;

int main() {
	// 輸入
	int N, X;
	cin >> N >> X;

	// 嘗試所有 (a, b, c) 的組合
	int answer = 0;
	for (int a = 1; a <= N; a++) {
		for (int b = a + 1; b <= N; b++) {
			for (int c = b + 1; c <= N; c++) {
				if (a + b + c == X) {
					answer += 1;
				}
			}
		}
	}

	// 輸出答案
	cout << answer << endl;

	return 0;
}