#include <iostream>
using namespace std;

int N, K, A[59];
int sum = 0; // A[1] + A[2] + ... + A[N] の値

int main() {
	// 輸入 → 求數列元素的總和sum
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) sum += A[i];

	// 輸出答案
	if (sum % 2 != K % 2) cout << "No" << endl;
	else if (sum > K) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
