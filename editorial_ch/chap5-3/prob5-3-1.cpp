#include <iostream>
using namespace std;

int main() {
	// 輸入
	long long H, W;
	cin >> H >> W;
	
	// 區分狀況
	if (H == 1 || W == 1) {
		cout << "1" << endl;
	}
	else {
		cout << (H * W + 1) / 2 << endl;
	}
	return 0;
}