# 重複平方法（p 取如 a^1, a^2, a^4, a^8, ... 的值）
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(60):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

# division(a, b, m) 為傳回 a÷b mod m 的函式
def division(a, b, m):
	return (a * modpow(b, m - 2, m)) % m

# 輸入
MOD = 1000000007
N = int(input())

# 計算答案
V = modpow(4, N + 1, MOD) - 1
Answer = division(V, 3, MOD)

# 輸出
print(Answer)