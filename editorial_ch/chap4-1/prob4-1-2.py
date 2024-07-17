# 輸入
N = int(input())
x = [0 for i in range(N)]
y = [0 for i in range(N)]
for i in range(N):
	x[i],y[i] = map(int, input().split())

# 全搜尋
Answer = 1000000000.0
for i in range(N):
	for j in range(i+1,N):
		dist = (((x[i] - x[j]) ** 2 + (y[i] - y[j]) ** 2) ** 0.5)
		Answer = min(Answer, dist)

# 輸出答案
print("%.12f" % Answer)
