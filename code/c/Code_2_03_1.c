#include <stdio.h>

int cnt = 1000;

int func1() {
	return 2021;
}

int func2(int pos) {
	cnt += 1;
	return cnt + pos;
}

int main() {
	printf("%d\n", func1()); // 輸出「2021」
	printf("%d\n", func2(500)); // 輸出「1501」
	printf("%d\n", func2(500)); // 輸出「1502」
	return 0;
}
