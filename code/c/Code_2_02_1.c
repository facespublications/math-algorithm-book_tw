#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	// 四則運算
	printf("%d\n", 869 + 120); // 輸出 989
	printf("%d\n", 869 - 120); // 輸出 749
	printf("%d\n", 869 * 120); // 輸出 104280
	printf("%d\n", 869 / 120); // 輸出 7 （注意在此只輸出整數部分）

	// 餘數（mod）
	printf("%d\n", 8 % 5); // 輸出 3
	printf("%d\n", 869 % 120); // 輸出 29

	// 絕對值（abs）（注： 在 C 語言中藥使用 abs 需 include <stdlib.h>）
	printf("%d\n", abs(-45)); // 輸出 45
	printf("%d\n", abs(15)); // 輸出 15

	// 乘方（pow）
	printf("%d\n", (int)pow(10.0, 2.0)); // 輸出 100
	printf("%d\n", (int)pow(3.0, 4.0)); // 輸出 81

	// 方根（sqrt）
	printf("%.5lf\n", sqrt(4.0)); // 輸出 2.00000
	printf("%.5lf\n", sqrt(2.0)); // 輸出 1.41421
	return 0;
}
