bool isprime(long long N) {
	// 設 N 為 2 以上整數，若 N 為質數則返回 true，若不是質數則返回 false
	for (long long i = 2; i <= N - 1; i++) {
		// N 被 i 整除時，此時可知不是質數
		if (N % i == 0) return false;
	}
	return true;
}
