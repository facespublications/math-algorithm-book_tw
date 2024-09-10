long long GCD(long long A, long long B) {
	if (B == 0) return A; // 基本情況
	return GCD(B, A % B);
}
