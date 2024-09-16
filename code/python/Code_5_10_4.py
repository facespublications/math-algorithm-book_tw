# 輸入
N = int(input())
S = input()

# 令'(' 的數量-')' 的數量為depth
# 如果 depth 在過程中變為負的話，此時為 No
depth = 0
flag = True
for i in range(N):
	if S[i] == '(':
		depth += 1
	if S[i] == ')':
		depth -= 1
	if depth < 0:
		flag = False

# 最後，也追加判定是否 depth=0['(' 和')' 的數量相同] 
if flag == True and depth == 0:
	print("Yes")
else:
	print("No")
