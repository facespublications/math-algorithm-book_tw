#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	for (long long i = 1; i * i <= N; i++) {
		if (N % i != 0) continue;
		cout << i << endl; // 追加因數 i
		if (i != N / i) {
			cout << N / i << endl; // i ≠ N/i 時，也追加因數 N/i
		}
	}
	return 0;
}
