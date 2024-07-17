import sys

# 進行深度優先搜尋的函式
def dfs(pos, G, visited, dp):
	visited[pos] = True
	dp[pos] = 1
	for i in G[pos]:
		if visited[i] == False:
			dfs(i, G, visited, dp)
			dp[pos] += dp[i]

# 將遞迴呼叫的深度上限設定為 120000
sys.setrecursionlimit(120000)

# 輸入
N = int(input())
A = [ None ] * (N - 1)
B = [ None ] * (N - 1)
for i in range(N - 1):
	A[i], B[i] = map(int, input().split())

# 製作鄰接表
G = [ list() for i in range(N + 1) ]
for i in range(N - 1):
	G[A[i]].append(B[i])
	G[B[i]].append(A[i])

# 使用深度優先搜尋 (DFS) 的動態規劃法
visited = [ False ] * (N + 1)
dp = [ None ] * (N + 1)
dfs(1, G, visited, dp)

# 計算答案並輸出
answer = 0
for i in range(2, N + 1):
	answer += dp[i] * (N - dp[i])
print(answer)