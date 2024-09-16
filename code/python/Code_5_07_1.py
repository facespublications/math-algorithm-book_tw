# 輸入
N = int(input())
A = list(map(int, input().split()))

# 求出答案
answer = 0
for i in range(N):
	# 在程式碼 5.7.1 (C++) 中為 A[i] * (-N + 2 * i - 1) ，但此處由於是從 i = 0 開始，因此是乘以 -N + 2 * i + 1。
	answer += A[i] * (-N + 2 * i + 1)

# 輸出答案
print(answer)
