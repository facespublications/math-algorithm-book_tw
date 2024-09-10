#include <stdio.h>

int N, K; long long X[59], Y[59];

int check_numpoints(long long lx, long long rx, long long ly, long long ry) {
	int cnt = 0;
	int i;
	for (i = 1; i <= N; i++) {
		// 判定長方形中是否包含點(X[i],Y[i])
		if (lx <= X[i] && X[i] <= rx && ly <= Y[i] && Y[i] <= ry) {
			cnt += 1;
		}
	}
	return cnt;
}

int main() {
	// 輸入
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld", &X[i], &Y[i]);
	}

	// 將左端x、右端x、下端y 和上端y 進行全搜尋（各自的編號為i,j,k,l）
	long long answer = (1LL << 62); // 設定成不可能的值
	int i, j, k, l;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (k = 1; k <= N; k++) {
				for (l = 1; l <= N; l++) {
					long long cl = X[i]; // 左端的 x 座標
					long long cr = X[j]; // 右端的 x 座標
					long long dl = Y[k]; // 下端的 y 座標
					long long dr = Y[l]; // 上端的 y 座標
					if (check_numpoints(cl, cr, dl, dr) >= K) {
						long long area = (cr - cl) * (dr - dl);
						if (answer > area) {
							answer = area;
						}
					}
				}
			}
		}
	}

	// 輸出答案
	printf("%lld\n", answer);
	return 0;
}
