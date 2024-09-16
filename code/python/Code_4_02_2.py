# 輸入
N, Q = map(int, input().split())
L = [ None ] * Q
R = [ None ] * Q
X = [ None ] * Q
for i in range(Q):
	L[i], R[i], X[i] = map(int, input().split())

# 階差的計算
B = [ 0 ] * (N + 2)
for i in range(Q):
	B[L[i]] += X[i]
	B[R[i] + 1] -= X[i]

# 計算並輸出答案
answer = ""
for i in range(2, N + 1):
	if B[i] > 0:
		answer += "<"
	if B[i] == 0:
		answer += "="
	if B[i] < 0:
		answer += ">"
print(answer)
