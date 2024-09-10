#include <iostream>
using namespace std;

long long N, S, A[61];

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 搜尋全部模式：（1LL << N）為 2 的 N 次方
	for (long long i = 0; i < (1LL << N); i++) {
		long long sum = 0;
		for (int j = 1; j <= N; j++) {
			// (i & (1LL << (j-1))) != 0LL 時，i 的二進制表示的倒數第 j 位是1
			// (1LL << (j-1)) 在 C++ 中代表「2 的 j-1 次方」
			if ((i & (1LL << (j-1))) != 0LL) sum += A[j];
		}
		if (sum == S) { cout << "Yes" << endl; return 0; }
	}
	cout << "No" << endl;
	return 0;
}
