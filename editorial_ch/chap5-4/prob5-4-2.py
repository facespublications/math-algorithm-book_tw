# 輸入
H, W = map(int, input().split())
A = [[] for i in range(H)]
for i in range(H):
	A[i] = list(map(int, input().split()))

# 計算列的總和
gyou = [0 for i in range(H)]
for i in range(H):
	for j in range(W):
		gyou[i] += A[i][j]

# 計算行的總和
retu = [0 for i in range(W)]
for j in range(W):
	for i in range(H):
		retu[j] += A[i][j]

# 對各網格計算答案
Answer = [[0 for j in range(W)] for i in range(H)]
for i in range(H):
	for j in range(W):
		Answer[i][j] = gyou[i] + retu[j] - A[i][j]

# 輸出
for i in range(H):
	print(*Answer[i])