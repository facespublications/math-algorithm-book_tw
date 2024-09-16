# 輸入 → 求數列元素的總和 S
N, K = map(int, input().split())
A = list(map(int, input().split()))
S = sum(A)

# 輸出答案
if S % 2 != K % 2:
	print("No")
elif S > K:
	print("No")
else:
	print("Yes")
