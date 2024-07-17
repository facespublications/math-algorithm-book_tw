# 輸入
N, S = map(int, input().split())
A = list(map(int, input().split()))

# 陣列的初始化
dp = [ [ None ] * (S + 1) for i in range(N + 1) ]
dp[0][0] = True
for i in range(1, S + 1):
	dp[0][i] = False

# 動態規劃法
for i in range(1, N + 1):
	for j in range(0, S + 1):
		if j < A[i - 1]:
			# j < A[i-1] 時，無法選擇卡 i
			dp[i][j] = dp[i - 1][j]
		else:
			# j >= A[i-1] 時，有選擇 / 不選擇 兩種選項
			if (dp[i - 1][j] == True or dp[i - 1][j - A[i - 1]] == True):
				dp[i][j] = True
			else:
				dp[i][j] = False

# 輸出答案
if dp[N][S] == True:
	print("Yes")
else:
	print("No")