# 輸入
N = int(input())

# 計算答案
Answer = 0.0
for i in range(1, N+1):
	Answer += 1.0 * N / i

# 輸出
print("%.12f" % Answer)