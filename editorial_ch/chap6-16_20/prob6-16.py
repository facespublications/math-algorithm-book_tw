# 輸入
N, X = map(int, input().split())

# 嘗試所有 (a, b, c) 的組合
answer = 0
for a in range(1, N + 1):
	for b in range(a + 1, N + 1):
		for c in range(b + 1, N + 1):
			if a + b + c == X:
				answer += 1

# 輸出答案
print(answer)