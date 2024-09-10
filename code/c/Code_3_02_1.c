#include <stdio.h>

// 返回正整數A 和B 的最大公因數的函式
// GCD 是Greatest Common Divisor（最大公因數）的縮寫
long long GCD(long long A, long long B) {
	long long answer = 0;
	long long i;
	for (i = 1; i <= A && i <= B; i++) {
		if (A % i == 0 && B % i == 0) {
			answer = i;
		}
	}
	return answer;
}

int main() {
	long long A, B;
	scanf("%lld%lld", &A, &B);
	printf("%lld\n", GCD(A, B));
	return 0;
}
