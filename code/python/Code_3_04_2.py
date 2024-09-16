# 輸入
N = int(input())
P = [ None ] * N
Q = [ None ] * N
for i in range(N):
	P[i], Q[i] = map(int, input().split())

# 計算答案（注意在 Python 3 中 Q[i] / P[i] 會計算到小數點）
answer = 0
for i in range(N):
	answer += Q[i] / P[i]

# 輸出
print("%.12f" % answer)
