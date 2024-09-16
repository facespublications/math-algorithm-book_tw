# 重複平方法（p 取 a^1、a^2、 a^4、a^8、⋯的值）
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(30):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

# division(a, b, m) 是回傳 a÷b mod m 的函式
def division(a, b, m):
	return (a * modpow(b, m - 2, m)) % m

# ncr 是 n! 除以 r!×(n-r)! 的值
def ncr(n, r):
	global fact, MOD
	return division(fact[n], fact[r] * fact[n - r] % MOD, MOD)

MOD = 1000000007
LIMIT = 200000

# 陣列 fact 的初始化（fact[i] 是 i 的階乘除以10000007 的餘數）
fact = [ None ] * (LIMIT + 1)
fact[0] = 1
for i in range(1, LIMIT + 1):
	fact[i] = fact[i - 1] * i % MOD

# 輸入 → 答案輸出
X, Y = map(int, input().split())
print(ncr(X + Y, Y))
