#include <iostream>
#include <algorithm>
using namespace std;

int N, S, A[69];
bool dp[69][10009];

int main() {
	// 輸入
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 陣列的初始化
	dp[0][0] = true;
	for (int i = 1; i <= S; i++) dp[0][i] = false;
	
	// 動態規劃法
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			// j < A[i] 時，無法選擇卡 i 
			if (j < A[i]) dp[i][j] = dp[i-1][j];
			// j >= A[i] 時，有選擇 / 不選擇 兩種選項
			if (j >= A[i]) {
				if (dp[i-1][j] == true || dp[i-1][j-A[i]] == true) dp[i][j] = true;
				else dp[i][j] = false;
			}
		}
	}
	
	// 輸出答案
	if (dp[N][S] == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}