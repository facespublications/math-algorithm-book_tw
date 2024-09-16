# 重複平方法（p 取 a^1、a^2、 a^4、a^8、⋯的值）
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(30):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

# division(a, b, m) 為回傳 a÷b mod m 的函式
def division(a, b, m):
	return (a * modpow(b, m - 2, m)) % m

# ncr 是 n! 除以 r!×(n-r)! 的值
def ncr(n, r):
	global fact, MOD
	return division(fact[n], fact[r] * fact[n - r] % MOD, MOD)

MOD = 1000000007
LIMIT = 200000

# 陣列化 fact 的初始（fact[i] 是i 的階乘除以10000007 的餘數）
fact = [ None ] * (LIMIT + 1)
fact[0] = 1
for i in range(1, LIMIT + 1):
	fact[i] = fact[i - 1] * i % MOD

# 輸入
N = int(input())
A = list(map(int, input().split()))

# 求出答案
answer = 0
for i in range(N):
	answer += A[i] * ncr(N - 1, i)
	answer %= MOD

# 輸出答案
print(answer)
