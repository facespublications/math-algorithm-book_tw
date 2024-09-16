# 注意
# 使用 Python 提交時，當 N = 100 時，執行時間大約需要 10 秒，可能會 TLE（超過執行時間限制）。
# 另一方面，若將相同的程式提交到 PyPy3，執行時間僅需約 0.5 秒，並且能夠 AC（通過測試）。

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
