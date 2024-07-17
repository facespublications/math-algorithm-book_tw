#include <stdio.h>
#include <stdlib.h>

int compare_values(const void* a, const void* b) {
	// 當 a 在前面時 回傳負值
	// 當 b 在前面時 回傳正值
	// 當 a 與 b 為相等的值時回傳 0 的函式
	if (*(long long*)a < *(long long*)b) return -1;
	if (*(long long*)a > *(long long*)b) return +1;
	return 0;
}

// 各個位數乘積的候選
int cand_size = 0;
long long fm_cand[10000000];

// 回傳 m 的各個位數乘積的函式
long long product(long long m) {
	long long ans = 1;
	if (m == 0) ans = 0;
	while (m >= 1) {
		ans *= (m % 10);
		m /= 10;
	}
	return ans;
}

// m 的位數為 11 位以下
void func(int digit, long long m) {
	if (digit == 11) {
		fm_cand[cand_size] = product(m);
		cand_size += 1;
		return;
	}
 
	// 搜尋下一位
	// min_value 為 cur 的最後一位（為了使其單調遞增，下一位必須為比它大的值）
	int min_value = (m % 10);
	for (int i = min_value; i <= 9; i++) {
		func(digit + 1, 10LL * m + 1LL * i);
	}
}
 
int main() {
	// 列舉 f(m) 的候選
	for (int i = 0; i <= 9; i++) {
		func(1, i);
	}
 
	// 將 fm_cand 排序
	qsort(fm_cand, cand_size, sizeof(long long), compare_values);
 
	// 輸入
	long long N, B;
	scanf("%lld%lld", &N, &B);
 
	// 檢查是否為 m - f(m) = B
	long long Answer = 0;
	for (int i = 0; i < cand_size; i++) {
		if (i >= 1 && fm_cand[i - 1] == fm_cand[i]) {
			// 不再檢查之前檢查過的元素
			continue;
		}
		long long m = fm_cand[i] + B;
		long long prod_m = product(m);
		if (prod_m == fm_cand[i] && m <= N) {
			Answer += 1;
		}
	}
 
	// 輸出
	printf("%lld\n", Answer);
	return 0;
}