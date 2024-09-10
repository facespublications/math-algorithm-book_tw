#include <stdio.h>
#include <stdbool.h>

// 設 N 為 2 以上整數，若 N 為質數則返回true，若不是質數則返回false
bool isprime(long long N) {
	long long i;
	for (i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	long long N;
	scanf("%lld", &N);
	if (isprime(N) == true) {
		printf("prime\n");
	}
	else {
		printf("not prime\n");
	}
	return 0;
}
