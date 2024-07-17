# 如果將本程式以 Python 提出，由於處理速度較慢，會導致超出執行時間限制（TLE）。
# 若以 PyPy3 提出，則能夠得到正確答案（AC）。

# 重複平方法（p 取 a**1, a**2, a**4, a**8, ... 等值）
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

# ncr 是將 n! 除以 r! × (n-r)! 的值
def ncr(n, r):
	global fact, MOD
	return division(fact[n], fact[r] * fact[n - r] % MOD, MOD)

MOD = 1000000007
LIMIT = 100000

# 陣列 fact 的初始化（fact[i] 為將 i 的階乘除以 1000000007 的餘數）
fact = [ None ] * (LIMIT + 1)
fact[0] = 1
for i in range(1, LIMIT + 1):
	fact[i] = fact[i - 1] * i % MOD

# 輸入 → 輸出答案
N = int(input())
for i in range(1, N + 1):
	answer = 0
	for j in range(1, (N - 1) // i + 2):
		answer += ncr(N - (i - 1) * (j - 1), j)
		answer %= MOD
	print(answer)