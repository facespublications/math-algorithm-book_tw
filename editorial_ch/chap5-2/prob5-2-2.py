# 輸入
N = int(input())
 
# 檢查是否以 N = 2^k-1 的形式表示
flag = False
for i in range(1, 60):
	if N == (2 ** i) - 1:
		flag = True
 
if flag == True:
	print("Second")
else:
	print("First")