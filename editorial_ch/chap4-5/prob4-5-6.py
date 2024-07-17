# 此程式是以 c[i-1][j-1] 代表方格 (i, j) 的形式進行實作。
# 令方格 (i, j) 的頂點編號為 i * W + j ，則頂點編號 0, 1, 2, ..., HW-1 的頂點會各有 1 個。

import queue

# 輸入
H, W = map(int, input().split())
sx, sy = map(int, input().split())
gx, gy = map(int, input().split())
c = [ input() for i in range(H) ]
start = (sx - 1) * W + (sy - 1)
goal = (gx - 1) * W + (gy - 1)

# 製作鄰接表
G = [ list() for i in range(H * W) ]

# 將橫向的邊 [(i, j) - (i, j+1)] 添加到圖中
for i in range(H):
	for j in range(W - 1):
		if c[i][j] == "." and c[i][j + 1] == ".":
			idx1 = i * W + j  # 方格 (i, j) 的頂點編號
			idx2 = i * W + (j + 1)  # 方格 (i, j + 1) 的頂點編號
			G[idx1].append(idx2)
			G[idx2].append(idx1)

# 將縱向的邊 [(i, j) - (i+1, j)] 添加到圖中
for i in range(H - 1):
	for j in range(W):
		if c[i][j] == "." and c[i + 1][j] == ".":
			idx1 = i * W + j  # 方格 (i, j) 的頂點編號
			idx2 = (i + 1) * W + j  # 方格 (i + 1, j) 的頂點編號
			G[idx1].append(idx2)
			G[idx2].append(idx1)

# 廣度優先搜尋的初始化 (dist[i] = -1 時，是未到達的白色頂點）
dist = [ -1 ] * (H * W)
Q = queue.Queue()
dist[start] = 0
Q.put(start) # 於 Q 添加 start

# 廣度優先搜尋
while not Q.empty():
	pos = Q.get() # 查看 Q 的開頭並將其取出
	for nex in G[pos]:
		if dist[nex] == -1:
			dist[nex] = dist[pos] + 1
			Q.put(nex) # 於 Q 添加 nex

# 輸出答案
print(dist[goal])
