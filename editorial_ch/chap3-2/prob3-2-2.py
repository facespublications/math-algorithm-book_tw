# 傳回正整數 A 和 B 的最大公因數的函式
def GCD(A, B):
	while A >= 1 and B >= 1:
		if A < B:
			B = B % A  # A < B 時，改寫較大的數 B
		else:
			A = A % B  # A >= B 時，改寫較大的數 A
	if A >= 1:
		return A
	return B

# 輸入
N = int(input())
A = list(map(int, input().split()))

# 求出答案
R = GCD(A[0], A[1])
for i in range(2, N):
	R = GCD(R, A[i])

# 輸出
print(R)