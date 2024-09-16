# 輸入
N, M = map(int, input().split())
A = [ None ] * M
B = [ None ] * M
for i in range(M):
	A[i], B[i] = map(int, input().split())

# 製作鄰接表
G = [ list() for i in range(N + 1) ] # G[i] 是與頂點 i 相鄰頂點的列表
for i in range(M):
	G[A[i]].append(B[i]) # 添加 B[i] 作為與頂點 A[i] 相鄰的頂點
	G[B[i]].append(A[i]) # 添加 A[i] 作為與頂點 B[i] 相鄰的頂點

# 輸出（len(G[i]) 為與頂點i 相鄰頂點的列表的大小 = 度）
for i in range(1, N + 1):
	output = str(i) + ": {"
	for j in range(len(G[i])):
		if j >= 1:
			output += ","
		output += str(G[i][j]) # G[i][j] 是與頂點　i 相鄰頂點之中的第 j+1 個頂點
	output += "}"
	print(output)
