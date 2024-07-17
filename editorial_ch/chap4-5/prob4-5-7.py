import sys

# 深度優先搜尋を行う関数
def dfs(pos, G, color):
	for i in G[pos]:
		if color[i] == 0:
			# color[pos] = 1 的時候為 2，color[pos] = 2 的時候為 1
			color[i] = 3 - color[pos]
			dfs(i, G, color)

# 將遞迴呼叫的深度上限設定為 210000
sys.setrecursionlimit(210000)

# 輸入
N, M = map(int, input().split())
A = [ None ] * M
B = [ None ] * M
for i in range(M):
	A[i], B[i] = map(int, input().split())

# 製作鄰接表
G = [ list() for i in range(N + 1) ]
for i in range(M):
	G[A[i]].append(B[i])
	G[B[i]].append(A[i])

# 深度優先搜尋
color = [ 0 ] * (N + 1)
for i in range(1, N + 1):
	if color[i] == 0:
		# 頂點 i 為白（尚未搜尋的連通成分）
		color[i] = 1
		dfs(i, G, color)

# 是否為二部圖的判斷
answer = True
for i in range(M):
	if color[A[i]] == color[B[i]]:
		answer = False
if answer == True:
	print("Yes")
else:
	print("No")
