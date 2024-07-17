#include <iostream>
using namespace std;

long long N;
long long A[500009];
long long x = 0, y = 0, z = 0;

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 計數 a、b、c、d 的個數
	for (int i = 1; i <= N; i++) {
		if (A[i] == 1) x += 1;
		if (A[i] == 2) y += 1;
		if (A[i] == 3) z += 1;
	}
	
	// 輸出
	cout << x * (x - 1) / 2 + y * (y - 1) / 2 + z * (z - 1) / 2 << endl;
	return 0;
}