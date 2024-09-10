bool isprime(long long N) {
	// 設 N 為 2 以上整數，若 N 為質數則返回true，若不是質數則返回false
	for (long long i = 2; i * i <= N; i++) {
		if (N % i == 0) return false;
	}
	return true;
}
