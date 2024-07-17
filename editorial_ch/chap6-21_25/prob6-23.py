# 輸入
L, R = map(int, input().split())

# 陣列的初始化、區分 L=1 時的狀況
isprime = [ True ] * (R - L + 1)
if L == 1:
	isprime[0] = False

# 篩選
LIMIT = int(R ** 0.5)
for i in range(2, LIMIT + 1):
	min_value = ((L + i - 1) // i) * i
	for j in range(min_value, R + 1, i):
		if j == i:
			continue
		isprime[j - L] = False

# 計數個數並輸出
answer = 0
for i in range(R - L + 1):
	if isprime[i] == True:
		answer += 1
print(answer)