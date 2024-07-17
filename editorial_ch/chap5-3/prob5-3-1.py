# 輸入
H, W = map(int, input().split())

# 區分狀況
if H == 1 or W == 1:
	print(1)
else:
	print((H * W + 1) // 2)