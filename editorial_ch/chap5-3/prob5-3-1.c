#include <stdio.h>

int main() {
	// 輸入
	long long H, W;
	scanf("%lld%lld", &H, &W);
	
	// 區分狀況
	if (H == 1 || W == 1) {
		printf("1\n");
	}
	else {
		printf("%lld\n", (H * W + 1LL) / 2LL);
	}
	return 0;
}