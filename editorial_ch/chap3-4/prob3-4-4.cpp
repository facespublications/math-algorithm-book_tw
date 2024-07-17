#include <iostream>
using namespace std;

int N;
double Answer = 0;

int main() {
	// 輸入
	cin >> N;
	
	// 求出期望值
	for (int i = N; i >= 1; i--) {
		Answer += 1.0 * N / i;
	}
	
	// 輸出
	printf("%.12lf\n", Answer);
	return 0;
}