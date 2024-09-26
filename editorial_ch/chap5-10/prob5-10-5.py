import sys

# 輸入
a, b, c = map(int, input().split())

# 區分 c = 1 時的狀況
if c == 1:
	print("No")
	sys.exit()

# 計算右邊（c 的 b 次方）
v = 1
for i in range(b):
	v *= c
	if a < v:
		print("Yes")
		sys.exit()

# 輸出（No 的情況）
print("No")