# 輸入
N = int(input())
A = list(map(int, input().split()))
M = int(input())
B = [0 for i in range(M)]
for i in range(M):
	B[i] = int(input())

# 取累積和
S = [0 for i in range(N)]
for i in range(1, N):
	S[i] = S[i - 1] + A[i - 1]

# 求出答案
# 寫成 B[i] - 1 的原因是因為陣列的 index 是從 0 開始
Answer = 0
for i in range(M-1):
	if B[i] < B[i + 1]:
		Answer += S[B[i + 1] - 1] - S[B[i] - 1]
	else:
		Answer += S[B[i] - 1] - S[B[i + 1] - 1]

# 輸出
print(Answer)