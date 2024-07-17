# 如果將本程式以 Python 提出，由於處理速度較慢，會導致超出執行時間限制（TLE）。
# 若以 PyPy3 提出，則能夠得到正確答案（AC）。

# 用盧卡斯定理計算 ncr mod 3
def ncr(n, r):
	if n < 3 and r < 3:
		A = [
			[ 1, 0, 0 ],
			[ 1, 1, 0 ],
			[ 1, 2, 1 ]
		]
		return A[n][r]
	return ncr(n // 3, r // 3) * ncr(n % 3, r % 3) % 3

# 輸入
N = int(input())
C = input()

# 求出答案
answer = 0
for i in range(N):
	code = "BWR".find(C[i])
	answer += code * ncr(N - 1, i)
	answer %= 3

# 將答案乘以 (-1)^(N-1) 
if N % 2 == 0:
	answer = (3 - answer) % 3

# 輸出答案（"BWR" 的第 answer 個字母）
print("BWR"[answer])