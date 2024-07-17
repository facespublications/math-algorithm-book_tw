#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	// 輸入
	long long a, b, c;
	cin >> a >> b >> c;
	
	// 區分 c = 1 時的狀況
	if (c == 1) {
		cout << "No" << endl;
		return 0;
	}
	
	// 計算右邊（c 的 b 次方）
	long long v = 1;
	for (long long i = 1; i <= b; i++) {
		if (a / c < v) {
			// 此條件分支只是將 a < (v * c) 換句話說
			// 進行條件換算的理由是 v, c 可能會達到 10^18 左右
			// 若進行 a < v * c，最差的情況下 v * c = 10^36 而產生溢出
			cout << "Yes" << endl;
			return 0;
		}
		v *= c;
	}
	
	// 迴圈無法中止的情況
	cout << "No" << endl;
	return 0;
}