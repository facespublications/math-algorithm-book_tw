# 此解法的計算複雜度為 O(N) （利用 5.7 節的技巧）
# 不只 PyPy3 (7.3.0) ，在 Python (3.8.2) 亦可 AC

N = int(input())
Answer = 0

for i in range(1, N+1):
	d = (N // i)
	Answer += i * (d * (d + 1) // 2)

print(Answer)