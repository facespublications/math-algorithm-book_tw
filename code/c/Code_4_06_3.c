#include <stdio.h>

int main() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	const long long MOD = 1000000007;
	long long answer = 1; // a 的 0 次方為 1，因此初始化成 Answer=1
	long long i;
	for (i = 1; i <= b; i++) {
		answer = (answer * a) % MOD;
	}
	printf("%lld\n", answer);
	return 0;
}
