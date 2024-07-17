#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N = 1000000;
	int M = 0;
	
	for (int i = 1; i <= N; i++) {
		double px = 6.0 * rand() / (double)RAND_MAX;
		double py = 9.0 * rand() / (double)RAND_MAX;
		
		// 與點 (3, 3) 之間的距離。若此值為 3 以下，則會被包含在半徑 3 的圓內。
		double dist_33 = sqrt((px - 3.0) * (px - 3.0) + (py - 3.0) * (py - 3.0));
		
		// 與點 (3, 7) 之間的距離。若此值為 2 以下，則會被包含在半徑 2 的圓內。
		double dist_37 = sqrt((px - 3.0) * (px - 3.0) + (py - 7.0) * (py - 7.0));
		
		// 條件分岐
		if (dist_33 <= 3.0 || dist_37 <= 2.0) M += 1;
	}
	
	// 輸出 N 次中有多少次進入表中
	cout << M << endl;
	return 0;
}