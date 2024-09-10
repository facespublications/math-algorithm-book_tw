// 返回正整數 A 和 B 的最大公因數的函式
// GCD 是Greatest Common Divisor（最大公因數）的縮寫
long long GCD(long long A, long long B) {
	long long Answer = 0;
	for (long long i = 1; i <= min(A, B); i++) {
		if (A % i == 0 && B % i == 0) Answer = i;
	}
	return Answer;
}
