# 輸入
N = int(input())
B = list(map(int, input().split()))
R = list(map(int, input().split()))

# 答案的計算（注意在 Python 3 では B[i] / N, R[i] / N 會計算到小數點）
blue = 0.0
red = 0.0
for i in range(N):
	blue += B[i] / N
	red += R[i] / N

# 輸出
print("%.12f" % (blue + red))
