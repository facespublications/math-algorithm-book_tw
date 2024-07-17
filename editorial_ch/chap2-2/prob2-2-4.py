# 輸入
N = int(input())
A = list(map(int, input().split()))

# 計算答案
Answer = 0
for i in range(N):
    Answer += A[i]

# 輸出
print(Answer % 100)
