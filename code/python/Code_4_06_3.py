MOD = 1000000007

a, b = map(int, input().split())

answer = 1  # a 的 0 次方為 1 ，所以將之初始化為 answer = 1
for i in range(b):
	answer = (answer * a) % MOD

print(answer)
