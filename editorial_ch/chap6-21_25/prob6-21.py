import math

r = 2.0 # 因為所求為 y = e^x 和 y = 2 的交點
a = 1.0 # 將初始值任意設定為 1.0
repeats = 5

for i in range(1, repeats + 1):
	# 求出點 (a, f(a)) 的 x 座標與 y 座標
	zahyou_x, zahyou_y = a, math.exp(a)
	
	# 求出切線式 y = sessen_a * x + sessen_b
	sessen_a = zahyou_y
	sessen_b = zahyou_y - sessen_a * zahyou_x
	
	# 求出下個 a 的值 next_a 
	next_a = (r - sessen_b) / sessen_a
	print("Step #%d: a = %.15f -> %.15f" % (i, a, next_a))
	a = next_a