#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	if (N % 4 == 0) cout << "Second" << endl; // 後手必勝
	else cout << "First" << endl; // 先手必勝
	return 0;
}
