# 輸入
N = int(input())
A = list(map(int, input().split()))

# 求出答案
a = 0
b = 0
c = 0
d = 0
for i in range(N):
	if A[i] == 100:
		a += 1
	if A[i] == 200:
		b += 1
	if A[i] == 300:
		c += 1
	if A[i] == 400:
		d += 1

# 輸出
print(a * d + b * c)