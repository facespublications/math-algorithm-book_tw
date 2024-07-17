# 回傳最大公因數的函式
def GCD(A, B):
	while A >= 1 and B >= 1:
		if A < B:
			B = B % A  # A < B 時，將較大的 B 改寫
		else:
			A = A % B  # A >= B 時，將較大的 A 改寫
	if A >= 1:
		return A
	return B

# 回傳最小公倍數的函式
def LCM(A, B):
	return int(A / GCD(A, B)) * B

# 輸入
N, K = map(int, input().split())
V = list(map(int, input().split()))

# 位元全搜尋
Answer = 0
for i in range(1, 1 << K):
	cnt = 0
	lcm = 1
	for j in range(K):
		if (i & (1 << j)) != 0:
			cnt += 1
			lcm = LCM(lcm, V[j])
			
	# num 是數的個數，此數為在 N 以下之中所選的所有數字的倍數
	num = N // lcm
	if cnt % 2 == 1:
		Answer += num
	else:
		Answer -= num

# 輸出
print(Answer)