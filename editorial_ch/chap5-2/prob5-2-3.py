import sys

# 輸入
N, K = map(int, input().split())
A = list(map(int, input().split()))

# 陣列的初始化
First = [-1 for i in range(N+1)]
Second = [-1 for i in range(N+1)]

# 求出答案
# cur 為現在所在城鎮的編號
cnt = 0
cur = 1
while True:
	# First, Second 更新
	if First[cur] == -1:
		First[cur] = cnt
	elif Second[cur] == -1:
		Second[cur] = cnt
	
	# K 回判斷在 K 次移動後是否位在城鎮 cur 
	if cnt == K:
		print(cur)
		sys.exit()
	elif Second[cur] != -1 and (K - First[cur]) % (Second[cur] - First[cur]) == 0:
		print(cur)
		sys.exit()
	
	cur = A[cur - 1]
	cnt += 1