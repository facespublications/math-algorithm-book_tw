# 求解小問題 t 的函式
def shou_mondai(A, B, t):
	cl = (A + t - 1) // t  # 將 A÷t 的小數點以下進位
	cr = B // t  # 將　B÷t 的小數點以下捨去
	if cr - cl >= 1:
		return True
	else:
		return False

A, B = map(int, input().split())
for i in range(1, B + 1):
	if shou_mondai(A, B, i) == True:
		answer = i
print(answer)
