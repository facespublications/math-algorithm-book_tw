#include <stdio.h>
#include <stdbool.h>

long long L, R; bool isprime[500009];

int main() {
	// 輸入
	scanf("%lld%lld", &L, &R);

	// 陣列的初始化
	long long i, j;
	for (i = 0; i <= R - L; i++) {
		isprime[i] = true;
	}

	// 區分出 L = 1 時的狀況（邊角案例）
	if (L == 1) {
		isprime[0] = false;
	}

	// 篩選
	for (i = 2; i * i <= R; i++) {
		long long min_value = ((L + i - 1) / i) * i; // 在 L 以上之最小的 i 的倍數
		// 將 L 以上 R 以下的所有（除 i 以外的）i 的倍數標記為×
		for (j = min_value; j <= R; j += i) {
			if (j == i) continue;
			isprime[j - L] = false;
		}
	}

	// 計數個數並輸出
	long long answer = 0;
	for (i = 0; i <= R - L; i++) {
		if (isprime[i] == true) {
			answer += 1;
		}
	}
	printf("%lld\n", answer);
	return 0;
}