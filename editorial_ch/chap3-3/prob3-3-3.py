# 輸入
n,r = map(int, input().split())

# 計算階乘
fact_n = 1
for i in range(1, n+1):
	fact_n *= i

fact_r = 1
for i in range(1, r+1):
	fact_r *= i

fact_nr = 1
for i in range(1, n-r+1):
	fact_nr *= i

# 輸出
print(int(fact_n / (fact_r * fact_nr)))