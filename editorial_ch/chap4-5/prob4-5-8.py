import heapq

# 輸入
K = int(input())

# 製作鄰接表 → 添加圖形的邊
G = [ list() for i in range(K) ]
for i in range(K):
	for j in range(10):
		if i == 0 and j == 0:
			continue
		G[i].append(((i * 10 + j) % K, j))

# Dijkstra法：陣列的初始化等
dist = [ 10 ** 10 ] * K
used = [ False ] * K
Q = list()
heapq.heappush(Q, (0, 0))  # 注意此處勿使 dist[0] = 0 ！

# Dijkstra法：優先佇列的更新
while len(Q) >= 1:
	pos = heapq.heappop(Q)[1]
	if used[pos] == True:
		continue
	used[pos] = True
	for i in G[pos]:
		to = i[0]
		cost = dist[pos] + i[1]
		if pos == 0:
			cost = i[1]  # 頂點 0 時為例外
		if dist[to] > cost:
			dist[to] = cost
			heapq.heappush(Q, (dist[to], to))

# 輸出答案
print(dist[0])
