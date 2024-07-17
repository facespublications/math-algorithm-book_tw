#include <iostream>
using namespace std;

int N;
double A[509], B[509], C[509];

bool check(double x, double y) {
	for (int i = 1; i <= N; i++) {
		if (A[i] * x + B[i] * y > C[i]) return false;
	}
	return true;
}

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i];
	
	// 將交點進行全搜尋
	double Answer = 0.0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			// 不具有交點時
			if (A[i] * B[j] == A[j] * B[i]) continue;
			
			// 求出第 i 條直線（條件式的邊界）與第 j 條直線（條件式的邊界）的交點
			double px = (C[i] * B[j] - C[j] * B[i]) / (A[i] * B[j] - A[j] * B[i]);
			double py = (C[i] * A[j] - C[j] * A[i]) / (B[i] * A[j] - B[j] * A[i]);
			bool ret = check(px - 0.00000001, py - 0.00000001);
			if (ret == true) {
				Answer = max(Answer, px + py);
			}
		}
	}
	
	// 輸出答案
	printf("%.12lf\n", Answer);
	return 0;
}