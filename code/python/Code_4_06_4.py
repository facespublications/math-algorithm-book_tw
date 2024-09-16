# 重複平方法（p 取 a^1、a^2、 a^4、a^8、⋯的值）
def modpow(a, b, m):
	p = a
	answer = 1
	for i in range(30):
		if (b & (1 << i)) != 0:
			answer = (answer * p) % m
		p = (p * p) % m
	return answer

MOD = 1000000007

a, b = map(int, input().split())
print(modpow(a, b, MOD))

# 補充說明
# 其實，在 Python 中可以使用標準庫中的函數 pow(a, b, m)，通過反覆平方法來求解「a**b 除以 m 的餘數」。
# Code_4_06_4_extra.py 是使用這個函數的程式，也請務必查看。
