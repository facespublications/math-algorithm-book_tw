#include <iostream>
using namespace std;

long long N, A[200009], Answer = 0;

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 求出答案→輸出答案
	for (int i = 1; i <= N; i++) Answer += A[i] * (-N + 2LL * i - 1LL);
	cout << Answer << endl;
	return 0;
}
