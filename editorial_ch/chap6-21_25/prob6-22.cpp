#include <iostream>
#include <algorithm>
using namespace std;

int N, T[109]; bool dp[109][100009];

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> T[i];
	
	// 陣列的初始化
	int sumT = 0;
	for (int i = 1; i <= N; i++) sumT += T[i];
	for (int i = 1; i <= sumT; i++) dp[0][i] = false;
	dp[0][0] = true;
	
	// 動態規劃法
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sumT; j++) {
			if (j < T[i]) {
				if (dp[i - 1][j] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
			if (j >= T[i]) {
				if (dp[i - 1][j] == true || dp[i - 1][j - T[i]] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
	}
	
	// 計算答案並輸出
	int answer = (1 << 30);
	for (int i = 0; i <= sumT; i++) {
		if (dp[N][i] == true) {
			int cooking_time = max(i, sumT - i);
			answer = min(answer, cooking_time);
		}
	}
	cout << answer << endl;
	
	return 0;
}