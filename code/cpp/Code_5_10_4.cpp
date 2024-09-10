#include <iostream>
#include <string>
using namespace std;

int N, depth = 0;
string S;

int main() {
	// 輸入
	cin >> N >> S;

	// 令'(' 的數量-')' 的數量為depth
	// 如果depth 在過程中變為負的話，此時為No
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') depth += 1;
		if (S[i] == ')') depth -= 1;
		if (depth < 0) {
			cout << "No" << endl;
			return 0;
		}
	}

	// 最後，根據是否depth=0['(' 和')' 的數量相同] 來區分情況
	if (depth == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
