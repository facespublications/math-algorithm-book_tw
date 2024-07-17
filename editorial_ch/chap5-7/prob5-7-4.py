# 輸入
N = int(input())
X = [0 for i in range(N)]
Y = [0 for i in range(N)]
for i in range(N):
	X[i], Y[i] = map(int, input().split())

# 將陣列 X, Y 排序
X.sort()
Y.sort()

# 部分 1 的答案（x座標的差的絕對值總和）
Part1 = 0
for i in range(1, N + 1):
	Part1 += X[i - 1] * (-N + 2 * i - 1);

# 部分 2 的答案（y 座標的差的絕對值總和）
Part2 = 0
for i in range(1, N + 1):
	Part2 += Y[i - 1] * (-N + 2 * i - 1);

# 輸出
print(Part1 + Part2)