#include <iostream>
using namespace std;

int N, A[100009], B[100009];
int Q, L[100009], R[100009];

int main() {
	// 輸入 → 求出累積和
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int j = 1; j <= Q; j++) cin >> L[j] >> R[j];
	B[0] = 0;
	for (int i = 1; i <= N; i++) B[i] = B[i - 1] + A[i];

	// 輸出答案
	for (int j = 1; j <= Q; j++) cout << B[R[j]] - B[L[j] - 1] << endl;
	return 0;
}
