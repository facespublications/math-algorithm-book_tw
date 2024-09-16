# 輸入
N = int(input())

# 動態規劃法
dp = [ None ] * (N + 1)
for i in range(N + 1):
	if i <= 1:
		dp[i] = 1
	else:
		dp[i] = dp[i - 1] + dp[i - 2]

# 輸出答案
print(dp[N])
