# 輸入
N = int(input())
A = list(map(int, input().split()))

# 選擇排序
for i in range(N - 1):
	min_position = i
	min_value = A[i]
	for j in range(i + 1, N):
		if A[j] < min_value:
			min_position = j  # min_position 為最小值的索引（0 ～ N-1）
			min_value = A[j]  # min_value 為當下的最小值
	# 交換 A[i] 與 A[min_position] 
	A[i], A[min_position] = A[min_position], A[i]

# 輸出
for i in range(N):
	print(A[i])
