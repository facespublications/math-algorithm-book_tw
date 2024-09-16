# 注意：以下的程式在 N >= 1 時能正確運行。
# 當 N = 0 時，答案應為「1」，因此需要另外進行條件分支處理。

N = int(input())
if N % 4 == 1:
	print(2)
if N % 4 == 2:
	print(4)
if N % 4 == 3:
	print(8)
if N % 4 == 0:
	print(6)
