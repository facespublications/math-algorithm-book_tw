# 注意
# 由於 Python 進行陣列的隨機訪問會花費較多時間，因此當 N = 100，W = 100000 時，執行時間大約需要 5 秒，可能會 TLE（超過執行時間限制）。
# 另一方面，如果將相同的程式提交到 PyPy3，執行時間只需要大約 0.5 秒，並且能夠 AC（通過測試）。

# 輸入
N, W = map(int, input().split())
w = [ None ] * N
v = [ None ] * N
for i in range(N):
	w[i], v[i] = map(int, input().split())

# 陣列的初始化
INF = 10 ** 18
dp = [ [ None ] * (W + 1) for i in range(N + 1) ]
dp[0][0] = 0
for i in range(1, W + 1):
	dp[0][i] = -INF

# 動態規劃法
for i in range(1, N + 1):
	for j in range(0, W + 1):
		if j < w[i - 1]:
			# j < w[i-1] 時，只能選擇方法 A
			dp[i][j] = dp[i - 1][j]
		else:
			# j >= w[i-1] 時，可以選擇方法 A、方法 B 的任一個
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1])

# 計算並輸出答案
answer = max(dp[N])
print(answer)
