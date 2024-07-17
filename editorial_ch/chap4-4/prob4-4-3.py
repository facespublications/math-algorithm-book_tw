# 重要注意
# 由於 Python 速度較慢，因此即使提出此程式，也可能超過執行時間限制（TLE）。
# 因此，請以「PyPy3（7.3.0）」提出完全相同的程式碼。或許可得到 AC。
# 如果想要了解計算複雜度更快的解法，請看「prob4-4-3_fast.py」。

# 輸入
N = int(input())
F = [0 for i in range(N + 1)]

# 計算 F[1], F[2], ..., F[N]
for i in range(1, N + 1):
	# 對 F[i], F[2i], F[3i], ... 加算 1
	for j in range(1, (N // i) + 1):
		F[j * i] += 1

# 求出答案
Answer = 0
for i in range(1, N + 1):
	Answer += i * F[i]

# 輸出
print(Answer)