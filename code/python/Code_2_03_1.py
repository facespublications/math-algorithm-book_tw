cnt = 1000

def func1():
	return 2021

def func2(pos):
	global cnt # 在函式內部使用全域變數 cnt
	cnt += 1
	return cnt + pos

print(func1()) # 輸出「2021」
print(func2(500)) # 輸出「1501」
print(func2(500)) # 輸出「1502」
