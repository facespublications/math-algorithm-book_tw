import random

N = 10000 # N 為測試次數（可適當變更）
M = 0
for i in range(N):
	px = random.random() # 生成 0 以上 1 未滿的亂數（雖然C++ 的程式碼 3.5.1 為生成 0 以上 1 以下的亂數，但幾乎相同）
	py = random.random() # 生成 0 以上 1 未滿的亂數（雖然C++ 的程式碼 3.5.1 為生成 0 以上 1 以下的亂數，但幾乎相同）
	# 與原點的距離為 sqrt(px * px + py * py)
	# 此值最好在1 以下，因此條件為「px * px + py * py <= 1」（與「sqrt(px * px + py * py) <= 1」同値）
	if px * px + py * py <= 1.0:
		M += 1

print("%.12f" % (4 * M / N))
