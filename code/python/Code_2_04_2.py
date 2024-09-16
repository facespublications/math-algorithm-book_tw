# 輸入
N, X, Y = map(int, input().split())

# 求出答案
cnt = 0
for i in range(1, N + 1):
	# mod 的計算請參考 2.2 節
	if i % X == 0 or i % Y == 0:
		cnt += 1

# 輸出
print(cnt)
