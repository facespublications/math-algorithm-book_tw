N = int(input())

answer = 0

# 10000 圓以上則繼續使用 10000 圓紙鈔
while N >= 10000:
	N -= 10000
	answer += 1

# 5000 圓以上則繼續使用 5000 圓紙鈔
while N >= 5000:
	N -= 5000
	answer += 1

# 剩餘金額使用 1000 圓紙鈔支付
while N >= 1:
	N -= 1000
	answer += 1

print(answer)
