# 輸入
N = int(input())
H = list(map(int, input().split()))

# 動態規劃法
dp = [ None ] * N
dp[0] = 0
for i in range(1, N):
	if i == 1:
		dp[i] = abs(H[i - 1] - H[i])
	if i >= 2:
		v1 = dp[i - 1] + abs(H[i - 1] - H[i])  # 跳躍到前 1 個跳台時
		v2 = dp[i - 2] + abs(H[i - 2] - H[i])  # 跳躍到前 2 個跳台時
		dp[i] = min(v1, v2)

# 輸出答案
print(dp[N - 1])
