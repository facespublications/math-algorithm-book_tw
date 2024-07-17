#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// 輸入
	long long N;
	cin >> N;

	// 將垂直長度從 1 到 √N 為止進行全搜尋
	long long answer = (1LL << 60);
	for (long long x = 1; x * x <= N; x++) {
		if (N % x == 0) {
			answer = min(answer, 2 * x + 2 * (N / x));
		}
	}

	//  輸出答案
	cout << answer << endl;

	return 0;
}