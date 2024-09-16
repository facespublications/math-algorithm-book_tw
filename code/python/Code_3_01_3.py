# 本程式與程式碼 3.1.3 不同，是由小到大輸出因數的程式。

# 輸入
N = int(input())

# 求所有因數，放入陣列 divisors
LIMIT = int(N ** 0.5)
divisors = []
for i in range(1, LIMIT + 1):
	if N % i == 0:
		divisors.append(i)
		if i != N // i:
			divisors.append(N // i)

# 由小到大排列 → 輸出
# sort 為由小到大排列的函式（於 3.6.1 項提及）
divisors.sort()
for i in divisors:
	print(i)
