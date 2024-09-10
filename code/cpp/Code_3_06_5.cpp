#include <iostream>
using namespace std;

int N, A[109];

int solve(int l, int r) {
	if (r - l == 1) return A[l];
	int m = (l + r) / 2; // 在區間 [l,r)的中央進行分割
	int s1 = solve(l, m); // s1為 A[l]+...+A[m-1]的合計值
	int s2 = solve(m, r); // s2為 A[m]+...+A[r-1] 的合計值
	return s1 + s2;
}

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 遞迴呼叫→輸出答案
	int Answer = solve(1, N + 1);
	cout << Answer << endl;
	return 0;
}
