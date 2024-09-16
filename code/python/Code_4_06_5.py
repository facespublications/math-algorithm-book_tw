# 重複平方法（p 取 a^1、a^2、 a^4、a^8、⋯的值）
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(30):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

# division(a, b, m) 是回傳　a÷b mod m 的函式
def division(a, b, m):
	return (a * modpow(b, m - 2, m)) % m

MOD = 1000000007

# 輸入
X, Y = map(int, input().split())

# 求出二項係數的分子和分母（步驟1./ 步驟2.）
bunshi, bunbo = 1, 1
for i in range(1, X + Y + 1):
	bunshi = (bunshi * i) % MOD
for i in range(1, X + 1):
	bunbo = (bunbo * i) % MOD
for i in range(1, Y + 1):
	bunbo = (bunbo * i) % MOD

# 答えを求める（手順 3.）
print(division(bunshi, bunbo, MOD))
