# 如果將本程式以 Python 提出，由於處理速度較慢，會導致超出執行時間限制（TLE）。
# 若以 PyPy3 提出，則能夠得到正確答案（AC）。

# 輸入
N = int(input())
T = list(map(int, input().split()))

# 陣列的初始化
sumT = sum(T)
dp = [ [ False ] * (sumT + 1) for i in range(N + 1) ]
dp[0][0] = True

# 動態規劃法
for i in range(1, N + 1):
	for j in range(sumT + 1):
		if j < T[i - 1]:
			if dp[i - 1][j] == True:
				dp[i][j] = True
			else:
				dp[i][j] = False
		if j >= T[i - 1]:
			if dp[i - 1][j] == True or dp[i - 1][j - T[i - 1]] == True:
				dp[i][j] = True
			else:
				dp[i][j] = False

# 計算答案並輸出
answer = 10 ** 10
for i in range(sumT + 1):
	if dp[N][i] == True:
		cooking_time = max(i, sumT - i)
		answer = min(answer, cooking_time)
print(answer)