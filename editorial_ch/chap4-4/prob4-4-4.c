#include <stdio.h>

int main() {
	// 參數的設定、初始化
	long long cnt = 0;
	double LIMIT = 23; // 將此設為 30 的話，答案即為所求
	double Current = 0;
	
	// 1 個 1 個相加
	while (Current < LIMIT) {
		cnt += 1;
		Current += 1.0 / cnt;
	}
	
	// 輸出答案
	printf("%lld\n", cnt);
	return 0;
}