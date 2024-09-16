# 這個原始碼為將深度優先搜尋 (DFS) 使用了堆疊的實作例。
# 堆疊為可進行「在最上層堆積元素」、「查找堆積在最上層的元素」、「刪除堆積在最上層的元素」三種操作的資料結構。
# 深度優先搜尋的部分為將程式碼 4.5.3 的 queue 變更為 stack，以此為基礎撰寫。

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

# 深度優先搜尋的初始化
visited = [ False ] * (N + 1)
S = list() # 定義堆疊 S 
visited[1] = True
S.append(1) # S 追加 1

# 深度優先搜尋
while len(S) >= 1:
	pos = S.pop() # 調查 S 的開頭並將之取出
	for nex in G[pos]:
		if visited[nex] == False:
			visited[nex] = True
			S.append(nex) # 追加 nex 至 S

# 判定是否連通（answer = true 時為連通）
answer = True
for i in range(1, N + 1):
	if visited[i] == False:
		answer = False
if answer == True:
	print("The graph is connected.")
else:
	print("The graph is not connected.")
