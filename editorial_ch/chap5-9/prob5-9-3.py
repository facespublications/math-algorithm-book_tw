# 輸入
# 注意 A 為 (結束時間, 開始時間) [為了以結束時間的遞增順序排序]
N = int(input())
A = []
for i in range(N):
	a, b = map(int, input().split())
	A.append([b, a])

# 排序
A.sort()

# 持續選擇結束時間最早的電影
CurrentTime = 0
Answer = 0
for i in range(N):
	if CurrentTime <= A[i][1]:
		CurrentTime = A[i][0]
		Answer += 1

# 輸出
print(Answer)