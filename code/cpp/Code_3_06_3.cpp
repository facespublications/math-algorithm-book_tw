#include <iostream>
using namespace std;

int func(int N) {
	if (N == 1) return 1; // 這種要區分開的情況稱為「基本情況」
	return func(N - 1) * N;
}

int main() {
	int N;
	cin >> N;
	cout << func(N) << endl;
	return 0;
}
