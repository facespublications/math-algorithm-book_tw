# 輸入
N = int(input())

# 求出答案
mod = 1000000007
val = N * (N + 1) // 2
print(val * val % mod)