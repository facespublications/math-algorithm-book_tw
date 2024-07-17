# 輸入
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 求出答案
Answer = 0.0
for i in range(N):
	Answer += (1.0 / 3.0) * A[i] + (2.0 / 3.0) * B[i]

# 輸出
print("%.12f" % Answer)