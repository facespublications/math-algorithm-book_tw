# 使用輾轉相除法求出最大公因數（也可以使用標準函式庫 math.gcd(A, B) 作為其他方法）
def GCD(A, B):
	if B == 0:
		return A
	return GCD(B, A % B)

# 輸入
A, B = map(int, input().split())

# 求出最小公倍數（注：在 Python 中不需在意溢出）
L = A * B // GCD(A, B)
if L > 10 ** 18:
	print("Large")
else:
	print(L)