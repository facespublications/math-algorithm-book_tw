r = 2.0 # 因為欲求√2
a = 2.0 # 將初始值任意設定為2.0
repeats = 5

for i in range(1, repeats + 1):
	# 求點(a, f(a)) 的　x 座標及　y 座標
	zahyou_x, zahyou_y = a, a * a
	
	# 求切線的方程式 y = sessen_a * x + sessen_b
	sessen_a = 2.0 * zahyou_x
	sessen_b = zahyou_y - sessen_a * zahyou_x
	
	# 求下一個 a 的值 next_a
	next_a = (r - sessen_b) / sessen_a
	print("Step #%d: a = %.12f -> %.12f" % (i, a, next_a))
	a = next_a
