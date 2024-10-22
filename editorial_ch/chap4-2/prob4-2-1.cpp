#include <iostream>
using namespace std;
 
long long N, A[200009], S[200009];
long long M, B[200009];
 
int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N - 1; i++) cin >> A[i];
	cin >> M;
	for (int i = 1; i <= M; i++) cin >> B[i];
	
	// 取累積和
	S[1] = 0;
	for (int i = 2; i <= N; i++) S[i] = S[i - 1] + A[i - 1];
	
	// 求出答案
	long long Answer = 0;
	for (int i = 1; i <= M - 1; i++) {
		if (B[i] < B[i + 1]) {
			Answer += (S[B[i + 1]] - S[B[i]]);
		}
		else {
			Answer += (S[B[i]] - S[B[i + 1]]);
		}
	}
	
	// 輸出
	cout << Answer << endl;
	return 0;
}