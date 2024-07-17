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

# 求出答案
answer = 0
for i in range(1, N + 1):
	cnt = 0
	for j in G[i]:
		if j < i:
			cnt += 1
	# 如果比自己的編號小的鄰接頂點為 1 個的話，將 answer 加 1
	if cnt == 1:
		answer += 1

# 輸出答案
print(answer)
