# 輸入
N = int(input())
A = [0.0 for i in range(N)]
B = [0.0 for i in range(N)]
C = [0.0 for i in range(N)]
for i in range(N):
	A[i], B[i], C[i] = map(float, input().split())

# 將交點進行全搜尋
Answer = 0.0
for i in range(0, N):
	for j in range(i + 1, N):
		# 交点を持たない場合
		if A[i] * B[j] == A[j] * B[i]:
			continue
		
		# 求出第 i 條直線（條件式的邊界）與第 j 條直線（條件式的邊界）的交點
		px = (C[i] * B[j] - C[j] * B[i]) / (A[i] * B[j] - A[j] * B[i]);
		py = (C[i] * A[j] - C[j] * A[i]) / (B[i] * A[j] - B[j] * A[i]);
		
		# 檢查座標 (px, py) 是否滿足所有的 N 個條件
		# 相當於 C++ 的程式碼中的 check 函式
		ret = True
		for k in range(N):
			if A[k] * px + B[k] * py > C[k]:
				ret = False
		
		if ret == True:
			Answer = max(Answer, px + py)

# 輸出
print("%.12f" % Answer)