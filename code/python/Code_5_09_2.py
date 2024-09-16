# 輸入
N = int(input())
L = [ None ] * N
R = [ None ] * N
for i in range(N):
	L[i], R[i] = map(int, input().split())

# 模擬電影的選擇方法
# 可觀看電影的結束時間最小值 min_endtime ，最初是設定成像 1000000 (以 INF 設定）這樣不可能的值
INF = 1000000
current_time = 0  # current_time 為現在時間（之前看完的電影的結束時間）
answer = 0
while True:
	min_endtime = INF
	for i in range(N):
		if L[i] >= current_time:
			min_endtime = min(min_endtime, R[i])
	if min_endtime == INF:
		break
	current_time = min_endtime
	answer += 1

# 輸出答案
print(answer)
