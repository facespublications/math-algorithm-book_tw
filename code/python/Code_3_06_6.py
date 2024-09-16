def func(N):
	# func(N) → func(N-1) → ... → func(0) → func(-1) → func(-2) → ... 會像這樣無限呼叫，程式無法正常運作
	return func(N - 1) * N

N = int(input())
print(func(N))
