# 輸入
N = int(input())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())
A, B = map(int, input().split())

# 計數交叉的次數
cnt = 0
for i in range(N):
	xa, ya = X[i] - A, Y[i] - B
	xb, yb = X[(i + 1) % N] - A, Y[(i + 1) % N] - B
	if ya > yb:
		xa, xb = xb, xa
		ya, yb = yb, ya
	if ya <= 0 and 0 < yb and xa * yb - xb * ya < 0:
		cnt += 1

# 輸出答案
if cnt % 2 == 1:
	print("INSIDE")
else:
	print("OUTSIDE")