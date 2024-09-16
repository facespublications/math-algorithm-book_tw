# 設 N 為 2 以上整數，若 N 為質數則返回 true，若不是質數則返回 false 的函式
def isprime(N):
	for i in range(2, N):
		if N % i == 0:
			return False # N 被 i 整除時，此時可知不是質數
	return True

N = int(input())
if isprime(N):
	print("prime")
else:
	print("not prime")
