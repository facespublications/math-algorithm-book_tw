#include <iostream>
using namespace std;

int N, A[200009];

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 選擇排序
	for (int i = 1; i <= N - 1; i++) {
		int Min = i, Min_Value = A[i];
		for (int j = i + 1; j <= N; j++) {
			if (A[j] < Min_Value) {
				Min = j; // Min 為最小值的索引（1 ∼ N）
				Min_Value = A[j]; // Min_Value 為當下的最小值
			}
		}
		swap(A[i], A[Min]);
	}

	// 輸出
	for (int i = 1; i <= N; i++) cout << A[i] << endl;
	return 0;
}
