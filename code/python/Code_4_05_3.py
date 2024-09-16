import queue

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

# 廣度優先搜尋的初始化（dist[i]=-1 時，為未到達的白色頂點）
dist = [ -1 ] * (N + 1)
Q = queue.Queue()
dist[1] = 0
Q.put(1) # 將 1 添加到 Q 中（操作 1）

# 廣度優先搜尋
while not Q.empty():
	pos = Q.get() # 查看 Q 的開頭並將之取出（操作2,3）
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.put(nex) # 將 nex 添加到 Q 中（操作 1）

# 輸出從頂點 1 到各頂點的最短距離
for i in range(1, N + 1):
	print(dist[i])
