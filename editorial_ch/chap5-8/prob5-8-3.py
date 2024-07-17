# 如果將本程式以 Python 提出，由於處理速度較慢，會導致超出執行時間限制（TLE）。
# 若以 PyPy3 提出，則能夠得到正確答案（AC）。

import heapq

# 輸入
N, M = map(int, input().split())
A, B, C = [ None ] * M, [ None ] * M, [ None ] * M
for i in range(M):
	A[i], B[i], C[i] = map(int, input().split())

# 製作鄰接表 → 添加圖的邊
G = [ list() for i in range(N + 1) ]
for i in range(M):
	G[A[i]].append((B[i], C[i]))
	G[B[i]].append((A[i], C[i]))

# Dijkstra法：陣列的初始化等
dist = [ 10 ** 19 ] * (N + 1)
used = [ False ] * (N + 1)
Q = list()
dist[1] = 0
heapq.heappush(Q, (0, 1))

# Dijkstra法：更新優先佇列
while len(Q) >= 1:
	pos = heapq.heappop(Q)[1]
	if used[pos] == True:
		continue
	used[pos] = True
	for i in G[pos]:
		to = i[0]
		cost = dist[pos] + i[1]
		if dist[to] > cost:
			dist[to] = cost
			heapq.heappush(Q, (dist[to], to))

# 輸出答案
if dist[N] != 10 ** 19:
	print(dist[N])
else:
	print(-1)