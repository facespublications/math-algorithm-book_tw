import math

# 輸入
ax, ay = map(int, input().split())
bx, by = map(int, input().split())
cx, cy = map(int, input().split())

# 求向量BA、BC、CA、CB 的分量表示
BAx, BAy = ax - bx, ay - by
BCx, BCy = cx - bx, cy - by
CAx, CAy = ax - cx, ay - cy
CBx, CBy = bx - cx, by - cy

# 判斷適用哪一個模式
pattern = 2
if BAx * BCx + BAy * BCy < 0:
	pattern = 1
if CAx * CBx + CAy * CBy < 0:
	pattern = 3

# 求出點與直線的距離
if pattern == 1:
	answer = math.sqrt(BAx ** 2 + BAy ** 2)
if pattern == 3:
	answer = math.sqrt(CAx ** 2 + CAy ** 2)
if pattern == 2:
	S = abs(BAx * BCy - BAy * BCx)
	BCLength = math.sqrt(BCx ** 2 + BCy ** 2)
	answer = S / BCLength

# 輸出答案
print("%.12f" % answer)
