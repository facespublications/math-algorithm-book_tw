def func(N):
	if N == 1:
		return 1  # 這種要區分開的情況稱為「基本情況」
	return func(N - 1) * N

N = int(input())
print(func(N))

# 在 Python 中，可呼叫的遞迴函數深度有一個上限，預設通常設為 1000 的深度。
# 這個上限可以通過呼叫 sys.getrecursionlimit() 來取得。
# 另外，可以通過呼叫 sys.setrecursionlimit(depth) 來更改遞迴呼叫深度的上限為指定的 depth。
# （要使用這些功能，首先需要寫上 import sys）
