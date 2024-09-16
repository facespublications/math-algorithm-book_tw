def solve(l, r, A):
	if r - l == 1:
		return A[l]
	m = (l + r) // 2  # 在區間 [l,r)的中央進行分割
	s1 = solve(l, m, A)  # s1為 A[l]+...+A[m-1]的合計值
	s2 = solve(m, r, A)  # s2為 A[m]+...+A[r-1] 的合計值
	return s1 + s2

# 輸入
N = int(input())
A = list(map(int, input().split()))

# 遞迴呼叫 → 輸出答案
answer = solve(0, N, A)
print(answer)
