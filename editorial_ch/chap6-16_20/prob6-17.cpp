#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// ��J
	long long N;
	cin >> N;

	// �N�������ױq 1 �� ��N ����i����j�M
	long long answer = (1LL << 60);
	for (long long x = 1; x * x <= N; x++) {
		if (N % x == 0) {
			answer = min(answer, 2 * x + 2 * (N / x));
		}
	}

	//  ��X����
	cout << answer << endl;

	return 0;
}