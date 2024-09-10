#include <iostream>
#include <algorithm>
using namespace std;

long long N, K, X[59], Y[59];
long long Answer = (1LL << 62); // 設定成不可能的值

int check_numpoints(int lx, int rx, int ly, int ry) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		// 判定長方形中是否包含點(X[i],Y[i])
		if (lx <= X[i] && X[i] <= rx && ly <= Y[i] && Y[i] <= ry) cnt++;
	}
	return cnt;
}

int main() {
	// 輸入
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];

	// 將左端x、右端x、下端y 和上端y 進行全搜尋（各自的編號為i,j,k,l）
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				for (int l = 1; l <= N; l++) {
					int cl = X[i]; // 左端的 x 座標
					int cr = X[j]; // 右端的 x 座標
					int dl = Y[k]; // 下端的 y 座標
					int dr = Y[l]; // 上端的 y 座標
					if (check_numpoints(cl, cr, dl, dr) >= K) {
						long long area = 1LL * (cr - cl) * (dr - dl);
						Answer = min(Answer, area);
					}
				}
			}
		}
	}

	// 答えの出力
	cout << Answer << endl;
	return 0;
}
