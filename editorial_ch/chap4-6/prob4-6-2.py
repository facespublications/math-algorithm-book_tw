# 重複平方法（p 取如 a^1, a^2, a^4, a^8, ... 的值）
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(30):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

# division(a, b, m) 為傳回 a÷b mod m 的函式
def division(a, b, m):
	return (a * modpow(b, m - 2, m)) % m

# 輸入
X, Y = map(int, input().split())
mod = 1000000007

# 狀況區分（a, b 會變成負的時候）
if (2 * Y - X) < 0 or (2 * X - Y) < 0:
	print(0)

# 狀況區分（a, b 不會成為整數的時候）
elif (2 * Y - X) % 3 != 0 or (2 * X - Y) % 3 != 0:
	print(0)

# 答案不為零的案例
else:
	bunshi = 1
	bunbo = 1
	a = (2 * Y - X) // 3
	b = (2 * X - Y) // 3
	
	# 求出二項係數的分子與分母（步驟 1. / 步驟 2.）
	for i in range(1, a + b + 1):
		bunshi *= i
		bunshi %= mod
	for i in range(1, a + 1):
		bunbo *= i
		bunbo %= mod
	for i in range(1, b + 1):
		bunbo *= i
		bunbo %= mod
	
	# 求出答案（步驟 3.）
	print(division(bunshi, bunbo, mod))