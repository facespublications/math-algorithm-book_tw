#include <iostream>
using namespace std;

int main() {
	// ��J
	int N, X;
	cin >> N >> X;

	// ���թҦ� (a, b, c) ���զX
	int answer = 0;
	for (int a = 1; a <= N; a++) {
		for (int b = a + 1; b <= N; b++) {
			for (int c = b + 1; c <= N; c++) {
				if (a + b + c == X) {
					answer += 1;
				}
			}
		}
	}

	// ��X����
	cout << answer << endl;

	return 0;
}