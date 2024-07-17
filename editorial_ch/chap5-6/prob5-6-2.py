# 輸入
N = int(input())
A = list(map(int, input().split()))

# 求出 2^i
mod = 1000000007
power = [0 for i in range(N)]
power[0] = 1
for i in range(1, N):
	power[i] = (2 * power[i - 1]) % mod

# 求出答案
Answer = 0
for i in range(N):
	Answer += power[i] * A[i]
	Answer %= mod

# 輸出
print(Answer)