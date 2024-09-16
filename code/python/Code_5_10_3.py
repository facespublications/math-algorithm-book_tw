# 輸入
N, X, Y = map(int, input().split())

# 4 個整數(a, b, c, d) 的全搜尋
flag = False
for a in range(1, N + 1):
	for b in range(a, N + 1):
		for c in range(b, N + 1):
			for d in range(c, N + 1):
				if a + b + c + d == X and a * b * c * d == Y:
					flag = True  # 如果找到答案的話 flag 為 true 

# 輸出答案
if flag == True:
	print("Yes")
else:
	print("No")

# 如 p.256 注 5.10.2 所述，由於 Python 的執行速度較慢，最大情況下執行可能需要數十秒。
# 然而，如果使用相同的程式在 PyPy3 上執行，即使在最大情況下也能在大約 1 秒內得到答案。
# 有關更優化的計算量程式，請參見 Code_5_10_3_extra.py。
