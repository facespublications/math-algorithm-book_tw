#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b); // 輸入 a 及 b
	printf("%d\n", a & b); // 輸出 a AND b的值
	printf("%d\n", a | b); // 輸出 a OR b的值
	printf("%d\n", a ^ b); // 輸出 a XOR b的值
	return 0;
}
