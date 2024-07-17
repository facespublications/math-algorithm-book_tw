# 在 Python，有一個用來求矩陣的 T 次方的函式在 numpy 的函式庫中。
# 使用此函式的話，可以用如下的非常簡短的程式來解決這個問題。
# 當然，也可以使用重複平方法來解決。關於這點，可以參考程式碼 4.7.1（Python 版）等。

import numpy as np

Q = int(input())
for i in range(Q):
	S = input().split()
	X, Y, Z, T = float(S[0]), float(S[1]), float(S[2]), int(S[3])
	A = np.array([[ 1 - X, Y, 0 ], [ 0, 1 - Y, Z ], [ X, 0, 1 - Z ]])
	answer = np.linalg.matrix_power(A, T)
	print("%.15f %.15f %.15f" % (sum(answer[0]), sum(answer[1]), sum(answer[2])))