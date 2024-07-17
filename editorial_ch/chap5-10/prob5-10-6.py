# 回傳整數 m 的各個位數乘積的函式
def product(m):
	if m == 0:
		return 0
	ans = 1
	while m >= 1:
		ans *= (m % 10)
		m //= 10
	return ans

# 將各個位數乘積的候選的集合回傳的函式
def func(digit, m):
	if digit == 11:
		return {product(m)}
	
	# 搜尋下一位
	# min_value 為 cur 的最後一位（為了使其單調遞增，下一位必須為比它大的值）
	min_value = m % 10
	ret = set()
	for i in range(min_value, 10):
		r = func(digit + 1, m * 10 + i)
		for j in r:
			ret.add(j)
	return ret

# 輸入
N, B = map(int, input().split())

# 列舉各個位數乘積的候選
fm_cand = func(0, 0)

# 檢查是否為 m - f(m) = B
Answer = 0
for fm in fm_cand:
	m = fm + B # 從各個位數的乘積推導之 m 的值
	prod_m = product(m) # 本來的 f(m) 的值
	if m - prod_m == B and m <= N:
		Answer += 1

# 輸出
print(Answer)