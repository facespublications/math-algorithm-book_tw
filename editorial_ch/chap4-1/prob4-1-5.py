# 向量 (ax, ay) 與 (bx, by) 的外積大小
def cross(ax, ay, bx, by):
	return ax * by - ay * bx

# 輸入
X1, Y1 = map(int, input().split())
X2, Y2 = map(int, input().split())
X3, Y3 = map(int, input().split())
X4, Y4 = map(int, input().split())

# 計算 cross 的值
ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);

# 全部排在一直線上時（邊角案例）
if ans1 == 0 and ans2 == 0 and ans3 == 0 and ans4 == 0:
	# 將　A, B, C, D 視為數值（正確來說是 pair 型態）
	# 藉由適當的進行 swap ，可以假設 A<B, C<D
	# 如此，可以歸結成判斷區間是否重疊的問題（節末問題 2.5.6）
	A = (X1, Y1) # 點 A 的座標
	B = (X2, Y2) # 點 B 的座標
	C = (X3, Y3) # 點 C 的座標
	D = (X4, Y4) # 點 D 的座標
	if A > B:
		tmp = B
		B = A
		A = tmp
	if C > D:
		tmp = D
		D = C
		C = tmp
	if max(A, C) <= min(B, D):
		print("Yes")
	else:
		print("No")

# 並非如此的普通狀況
else:
	IsAB = False # IsAB: 線段 AB 是否將點 C, D 分開？
	IsCD = False # IsCD: 線段 CD 是否將點 A, B 分開？
	if ans1 >= 0 and ans2 <= 0:
		IsAB = True
	if ans1 <= 0 and ans2 >= 0:
		IsAB = True
	if ans3 >= 0 and ans4 <= 0:
		IsCD = True
	if ans3 <= 0 and ans4 >= 0:
		IsCD = True
	
	# 輸出答案
	if IsAB == True and IsCD == True:
		print("Yes")
	else:
		print("No")