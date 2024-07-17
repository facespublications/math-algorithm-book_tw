# 輸入
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# 將陣列 A, B 排序
A.sort()
B.sort()

# 求出答案
Answer = 0
for i in range(N):
	Answer += abs(A[i] - B[i])

# 輸出
print(Answer)