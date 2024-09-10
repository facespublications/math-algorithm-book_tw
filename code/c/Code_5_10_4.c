#include <stdio.h>

int main() {
	// 輸入
	int N; char S[500009];
	scanf("%d%s", &N, S);

	// 令'(' 的數量-')' 的數量為depth
	// 如果depth 在過程中變為負的話，此時為No
	int depth = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') depth += 1;
		if (S[i] == ')') depth -= 1;
		if (depth < 0) {
			printf("No\n");
			return 0;
		}
	}

	// 最後，根據是否depth=0['(' 和')' 的數量相同] 來區分情況
	if (depth == 0) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
