# 輸入 → 陣列 prime 的初始化
N = int(input())
prime = [ True ] * (N + 1)

# 埃拉托斯特尼篩
LIMIT = int(N ** 0.5)
for i in range(2, LIMIT + 1):
	if prime[i] == True:
		# x = 2i, 3i, 4i, ... 像這樣，N 以下的範圍不斷迴圈
		for j in range(2 * i, N + 1, i):
			prime[j] = False

# 將 N 以下的質數以從小到大的順序輸出
for i in range(2, N + 1):
	if prime[i] == True:
		print(i)
