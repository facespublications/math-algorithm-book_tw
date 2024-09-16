from copy import deepcopy

MOD = 1000000000

# 回傳　2×2 矩陣 A、B 乘積的函式
def multiply(A, B):
	global MOD
	C = [ [ 0, 0 ], [ 0, 0 ] ]
	for i in range(2):
		for j in range(2):
			for k in range(2):
				C[i][j] += A[i][k] * B[k][j]
				C[i][j] %= MOD
	return C

# 回傳 A 的 n 次方的函式
def power(A, n):
	P = deepcopy(A)
	Q = [ [ 0, 0 ], [ 0, 0 ] ]
	flag = False
	for i in range(60):
		if (n & (1 << i)) != 0:
			if flag == False:
				Q = deepcopy(P)
				flag = True
			else:
				Q = deepcopy(multiply(Q, P))
		P = deepcopy(multiply(P, P))
	return Q

# 輸入 → 乘方的計算（請注意，N 必須大於 2 才能正常運作）
N = int(input())
A = [ [ 1, 1 ], [ 1, 0 ] ]
B = power(A, N - 1)

# 計算答案 → 輸出（請注意，倒數第 9 位為 0 時，以開頭不含 0 的形式輸出）
answer = (B[1][0] + B[1][1]) % MOD
print(answer)
