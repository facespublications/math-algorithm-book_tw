# 輸入
N, S = map(int, input().split())
A = list(map(int, input().split()))

# 搜尋全部模式：（1L << N）為 2 的 N 次方
answer = "No"
for i in range(0, 1 << N):
	partsum = 0
	for j in range(0, N):
		# (i & (1 << j)) != 0LL 時，i 的二進制表示的倒數第 j+1 位是 1
		# (1 << j) 在 Python 中代表「2 的 j 次方」
		if (i & (1 << j)) != 0:
			partsum += A[j]
	if partsum == S:
		answer = "Yes"
		break

# 輸出
print(answer)
