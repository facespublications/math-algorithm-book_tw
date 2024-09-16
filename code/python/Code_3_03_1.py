# 注意
# 以 Python 提出的話，若 N = 100 實行需要 10 秒程度的時間，會是TLE（超過實行時間限制）。
# 另一方面，以 PyPy3 提出同一個程式，實行只需要 0.5 秒程度的時間，可以達成AC（正解）。

# 輸入
N = int(input())
A = list(map(int, input().split()))

# 對 5 張卡片的編號(i, j, k, l, m) 進行全搜尋
answer = 0
for i in range(0, N):
	for j in range(i + 1, N):
		for k in range(j + 1, N):
			for l in range(k + 1, N):
				for m in range(l + 1, N):
					if A[i] + A[j] + A[k] + A[l] + A[m] == 1000:
						answer += 1

# 輸出
print(answer)
