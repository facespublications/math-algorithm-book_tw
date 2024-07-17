# 輸入
N = int(input())

# 將垂直長度從 1 到 √N 為止進行全搜尋
LIMIT = int(N ** 0.5)
answer = 10 ** 19
for i in range(1, LIMIT + 1):
	if N % i == 0:
		answer = min(answer, 2 * i + 2 * (N // i))

# 輸出答案
print(answer)