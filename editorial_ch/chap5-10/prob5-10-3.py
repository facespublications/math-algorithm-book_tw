# 輸入
A, B, C = map(int, input().split())

# 計算
mod = 998244353
D = A * (A + 1) // 2
E = B * (B + 1) // 2
F = C * (C + 1) // 2

# 輸出答案
print((D * E * F) % mod)