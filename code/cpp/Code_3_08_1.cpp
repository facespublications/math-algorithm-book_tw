#include <iostream>
#include <algorithm>
using namespace std;

long long N, X, A[1000009];

int main() {
	// 輸入
	cin >> N >> X;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 陣列的排序
	sort(A + 1, A + N + 1);

	// 二元搜尋
	int left = 1, right = N;
	while (left <= right) {
		int mid = (left + right) / 2; // 以搜尋範圍的中央進行分割
		if (A[mid] == X) { cout << "Yes" << endl; return 0; }
		if (A[mid] > X) right = mid - 1; // 將搜尋範圍縮小到前半部分
		if (A[mid] < X) left = mid + 1; // 將搜尋範圍縮小到後半部分
	}

	// 當搜尋範圍耗盡仍非　Yes 時，答案即為No
	cout << "No" << endl;
	return 0;
}
