#include <stdio.h>
#include <stdbool.h>
 
long long N, K;
long long A[200009];
long long First[200009], Second[200009];
 
int main() {
	// 輸入
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	
	// 陣列的初始化
	for (int i = 1; i <= N; i++) First[i] = -1;
	for (int i = 1; i <= N; i++) Second[i] = -1;
	
	// 求出答案
	// cur 為現在所在城鎮的編號
	long long cnt = 0, cur = 1;
	while (true) {
		// First, Second 更新
		if (First[cur] == -1) First[cur] = cnt;
		else if (Second[cur] == -1) Second[cur] = cnt;
		
		// 判斷在 K 次移動後是否位在城鎮 cur 
		if (cnt == K) {
			printf("%lld\n", cur);
			return 0;
		}
		else if (Second[cur] != -1 && (K - First[cur]) % (Second[cur] - First[cur]) == 0) {
			printf("%lld\n", cur);
			return 0;
		}
		
		// 位置更新
		cur = A[cur];
		cnt += 1;
	}
	return 0;
}