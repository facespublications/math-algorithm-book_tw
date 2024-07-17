#include <iostream>
using namespace std;

long long GCD(long long A, long long B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}

int main() {
	// —A“ü
	long long A, B;
	cin >> A >> B;

	// ”»ÐÅ¬Œö”{É¥”Û’´‰ß 10^18
	if (A / GCD(A, B) > 1000000000000000000 / B) {
		cout << "Large" << endl;
	}
	else {
		cout << A / GCD(A, B) * B << endl;
	}
	return 0;
}