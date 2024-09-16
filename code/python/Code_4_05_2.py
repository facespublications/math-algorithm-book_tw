import sys

# 進行深度優先搜尋的函式
def dfs(pos, G, visited):
	visited[pos] = True
	for i in G[pos]:
		if visited[i] == False:
			dfs(i, G, visited)

# 將遞迴呼叫深度上限設為 120000 
sys.setrecursionlimit(120000)

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
visited = [ False ] * (N + 1)
dfs(1, G, visited)

# 判定是否連通（answer=true 時為連通）
answer = True
for i in range(1, N + 1):
	if visited[i] == False:
		answer = False
if answer == True:
	print("The graph is connected.")
else:
	print("The graph is not connected.")
