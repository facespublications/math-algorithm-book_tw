cnt = 0
LIMIT = 23 # 將此設為 30 的話，答案即為所求
Current = 0

# 1 個 1 個相加
while Current < LIMIT:
	cnt += 1
	Current += 1.0 / cnt

# 輸出
print(cnt)