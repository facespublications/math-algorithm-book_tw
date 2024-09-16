# 返回正整數 A 和 B 的最大公因數的函式
# GCD 是Greatest Common Divisor（最大公因數）的縮寫
def GCD(A, B):
	while A >= 1 and B >= 1:
		if A < B:
			B = B % A  # A < B時，改寫較大的數B
		else:
			A = A % B  # A >= B時，改寫較大的數A
	if A >= 1:
		return A
	return B

A, B = map(int, input().split())
print(GCD(A, B))
