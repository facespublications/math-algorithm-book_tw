def check_numpoints(N, X, Y, lx, rx, ly, ry):
	cnt = 0
	for i in range(N):
		# 判定長方形中是否包含點 (X[i],Y[i])
		if lx <= X[i] and X[i] <= rx and ly <= Y[i] and Y[i] <= ry:
			cnt += 1
	return cnt

# 輸入
N, K = map(int, input().split())
X = [ None ] * N
Y = [ None ] * N
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 將左端x、右端x、下端y 和上端y 進行全搜尋（各自的編號為i,j,k,l）
answer = 10 ** 19  # 設定成不可能的值
for i in range(N):
	for j in range(N):
		for k in range(N):
			for l in range(N):
				# cl <= x <= cr, dl <= y <= dr 的長方形
				# 要製作長方形，必須 cl < cr, dl < dr
				cl, cr, dl, dr = X[i], X[j], Y[k], Y[l]
				if cl < cr and dl < dr:
					if check_numpoints(N, X, Y, cl, cr, dl, dr) >= K:
						area = (cr - cl) * (dr - dl)
						answer = min(answer, area)

# 輸出答案
print(answer)

# 這個問題對執行時間的限制很嚴格，如果使用程式碼 5.5.2 的寫法，即使在 PyPy3 上也可能需要最多 2.5 秒的執行時間，提交到 AtCoder 會導致 TLE（超過執行時間限制）。
# 然而，如果限制只探索滿足「cl < cr」和「dl < dr」的情況，探索的長方形數量將大約減少至 1/4。
# 利用這一點的程式如果在 PyPy3 上提交，則能在 1 秒內完成執行並得到正確答案（AC）。
