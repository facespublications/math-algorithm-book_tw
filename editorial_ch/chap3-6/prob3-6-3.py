def MergeSort(A):
	# 長度為 1 時，因為已經被排序完成，所以什麼都不用做
	if len(A) == 1:
		return A
	
	# 分割成 2 個之後，將較小的陣列排序
	m = len(A) // 2
	A_Dash = MergeSort(A[0:m])
	B_Dash = MergeSort(A[m:len(A)])
	
	# 此時，以下 2 個陣列已被排序：
	# 相當於列 A' 的 [A_Dash[0], A_Dash[1], ..., A_Dash[m-1]]
	# 相當於列 B' 的 [B_Dash[0], B_Dash[1], ..., B_Dash[len(A)-m-1]]
	# 以下為 Merge 操作。
	c1 = 0
	c2 = 0
	C = []
	while (c1 < len(A_Dash) or c2 < len(B_Dash)):
		if c1 == len(A_Dash):
			# 列 A' 為空時
			C.append(B_Dash[c2])
			c2 += 1
		elif c2 == len(B_Dash):
			# 列 B' 為空時
			C.append(A_Dash[c1])
			c1 += 1
		else:
			# 兩者都不是時
			if A_Dash[c1] <= B_Dash[c2]:
				C.append(A_Dash[c1])
				c1 += 1
			else:
				C.append(B_Dash[c2])
				c2 += 1
	
	# 傳回合併了列 A'、列 B' 的陣列 C
	return C

# 以下，主要部分
N = int(input())
A = list(map(int, input().split()))

# 合併排序 → 輸出答案
Answer = MergeSort(A)
print(*Answer)