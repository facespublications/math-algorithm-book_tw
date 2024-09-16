# 設 N 為 2 以上整數，若 N 為質數則返回true，若不是質數則返回false的函式
def isprime(N):
	LIMIT = int(N ** 0.5)
	for i in range(2, LIMIT + 1):
		if N % i == 0:
			return False
	return True

N = int(input())
if isprime(N):
	print("prime")
else:
	print("not prime")
