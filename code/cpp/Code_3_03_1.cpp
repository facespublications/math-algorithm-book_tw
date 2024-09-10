#include <iostream>
using namespace std;

int N, A[109];
int Answer = 0;

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 對 5 張卡片的編號(i, j, k, l, m) 進行全搜尋
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				for (int l = k + 1; l <= N; l++) {
					for (int m = l + 1; m <= N; m++) {
						if (A[i] + A[j] + A[k] + A[l] + A[m] == 1000) Answer += 1;
					}
				}
			}
		}
	}

	// 答案的輸出
	cout << Answer << endl;
	return 0;
}
