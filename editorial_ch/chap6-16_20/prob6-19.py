# 輸入（注意陣列 B 的索引從 0 開始）
N = int(input())
B = list(map(int, input().split()))

# 求出數列 A 的元素總和
answer = B[0] + B[N - 2]
for i in range(1, N - 1):
	answer += min(B[i - 1], B[i])

# 輸出答案
print(answer)