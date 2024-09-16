# 輸入
N, X = map(int, input().split())
A = list(map(int, input().split()))

# 陣列的排序
A.sort()

# 二元搜尋
answer = "No"
left, right = 0, N - 1
while left <= right:
	mid = (left + right) // 2
	if A[mid] == X:
		answer = "Yes"
		break
	if A[mid] > X:
		# 將搜尋範圍縮小到前半部分
		right = mid - 1
	if A[mid] < X:
		# 將搜尋範圍縮小到後半部分
		left = mid + 1

# 輸出答案
print(answer)
