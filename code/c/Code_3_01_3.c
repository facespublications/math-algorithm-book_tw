#include <stdio.h>

int main() {
	long long N;
	scanf("%lld", &N);
	long long i;
	for (i = 1; i * i <= N; i++) {
		if (N % i != 0) continue;
		printf("%lld\n", i); // 追加因數 i
		if (i != N / i) {
			printf("%lld\n", N / i); // i ≠ N/i時，也追加因數 N/i
		}
	}
	return 0;
}
