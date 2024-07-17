#include <iostream>
using namespace std;

long long N;
long long A[200009];
long long a = 0, b = 0, c = 0, d = 0; // 為了避免溢出，使用 64 位元的整數

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 計數 a、b、c、d 的個數
	for (int i = 1; i <= N; i++) {
		if (A[i] == 100) a += 1;
		if (A[i] == 200) b += 1;
		if (A[i] == 300) c += 1;
		if (A[i] == 400) d += 1;
	}
	
	// 輸出（答案為 a * d + b * c）
	cout << a * d + b * c << endl;
	return 0;
}