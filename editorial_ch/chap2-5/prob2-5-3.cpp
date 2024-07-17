#include <iostream>
using namespace std;

int main() {
	long long N;
	long long Answer = 1;
	cin >> N;
	for (int i = 2; i <= N; i++) Answer *= i; // 將Answer 乘以 i
	cout << Answer << endl;
	return 0;
}