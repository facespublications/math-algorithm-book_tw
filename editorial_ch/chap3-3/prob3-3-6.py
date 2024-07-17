# 輸入
N = int(input())
A = list(map(int, input().split()))

# 求出答案
cnt = [0 for i in range(100000)]
for i in range(N):
	cnt[A[i]] += 1

Answer = 0
for i in range(1, 50000):
	Answer += cnt[i] * cnt[100000 - i]
Answer += cnt[50000] * (cnt[50000] - 1) // 2

# 輸出
print(Answer)