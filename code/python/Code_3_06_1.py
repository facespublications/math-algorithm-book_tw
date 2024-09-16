# 輸入（例如輸入了 N = 5, A = [3, 1, 4, 1, 5] ）
N = int(input())
A = list(map(int, input().split()))

# 排序陣列 A 整體
A.sort()

# 輸出（按照1、1、3、4、5 的順序輸出）
for i in range(N):
	print(A[i])
