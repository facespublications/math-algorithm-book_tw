# 輸入
X1,Y1,R1 = map(float, input().split())
X2,Y2,R2 = map(float, input().split())

# 求出圓心之間的距離
d = (((X1 - X2) ** 2 + (Y1 - Y2) ** 2) ** 0.5)

# 輸出答案
if d < abs(R1 - R2):
	print("1")
elif d == abs(R1 - R2):
	print("2")
elif d < R1 + R2:
	print("3")
elif d == R1 + R2:
	print("4")
else:
	print("5")