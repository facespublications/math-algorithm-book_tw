#include <iostream>
using namespace std;

int N, S;
long long Answer = 0;

int main() {
	// 入力
	cin >> N >> S;

	// 答えを求める
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i + j <= S) Answer += 1;
		}
	}

	// 出力
	cout << Answer << endl;
	return 0;
}