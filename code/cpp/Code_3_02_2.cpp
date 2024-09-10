// GCD 是Greatest Common Divisor（最大公因數）的縮寫
long long GCD(long long A, long long B) {
	while (A >= 1 && B >= 1) {
		if (A < B) B = B % A; // A<B時，改寫較大的數B
		else A = A % B; // A >= B時，改寫較大的數A
	}
	if (A >= 1) return A;
	return B;
}
