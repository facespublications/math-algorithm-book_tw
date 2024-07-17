# 輸入
N = int(input())
A = list(map(int, input().split()))

# 將陣列 A 全部排序
A.sort()

# 求出答案
Answer = 0
for i in range(1, N + 1):
	Answer += A[i - 1] * (-N + 2 * i - 1)

# 輸出
print(Answer)