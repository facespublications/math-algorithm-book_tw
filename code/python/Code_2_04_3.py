# 輸入
N, S = map(int, input().split())

# 求出答案
answer = 0
for i in range(1, N + 1):
	for j in range(1, N + 1):
		if i + j <= S:
			answer += 1

# 輸出
print(answer)
