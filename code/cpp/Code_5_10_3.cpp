#include <iostream>
using namespace std;

long long N, X, Y;

int main() {
	// 輸入
	cin >> N >> X >> Y;

	// 4 個整數(a, b, c, d) 的全搜尋→輸出答案
	for (int a = 1; a <= N; a++) {
		for (int b = a; b <= N; b++) {
			for (int c = b; c <= N; c++) {
				for (int d = c; d <= N; d++) {
					if (a + b + c + d == X && 1LL * a * b * c * d == Y) {
						cout << "Yes" << endl;
						return 0; // 使程式結束執行
					}
				}
			}
		}
	}
	cout << "No" << endl; // 如果連 1 組都沒發現的話為No
	return 0;
}
