# 返回正整數 A 和 B 的最大公因數的函式
# GCD 是Greatest Common Divisor（最大公因數）的縮寫
def GCD(A, B):
	answer = 0
	for i in range(1, min(A, B) + 1):
		if A % i == 0 and B % i == 0:
			answer = i
	return answer

A, B = map(int, input().split())
print(GCD(A, B))
