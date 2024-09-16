# 輸入
N, K = map(int, input().split())

# 算出事件 B 的個數 yojishou
yojishou = 0
for a in range(1, N + 1):
	l = max(1, a - (K - 1)) # b, c 的搜尋範圍下限 l
	r = min(N, a + (K - 1)) # b, c 的搜尋範圍上限 r
	for b in range(l, r + 1):
		for c in range(l, r + 1):
			if abs(b - c) <= K - 1:
				yojishou += 1

# 輸出答案
print(N ** 3 - yojishou)
