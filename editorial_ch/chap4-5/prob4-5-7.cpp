#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[200009], B[200009]; // N, M ≦ 200000 ，因此使陣列的大小為 200009 
vector<int> G[200009];
int color[200009];

void dfs(int pos) {
	for (int i : G[pos]) { // 範圍 for 敘述
		if (color[i] == 0) {
			// color[pos]=1 的時候為 2，color[pos] = 2 的時候為 1
			color[i] = 3 - color[pos];
			dfs(i);
		}
	}
}

int main() {
	// 輸入
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	
	// 深度優先搜尋
	for (int i = 1; i <= N; i++) color[i] = 0;
	for (int i = 1; i <= N; i++) {
		if (color[i] == 0) {
			// 頂點 i 為白（尚未搜尋的連通成分）
			color[i] = 1;
			dfs(i);
		}
	}
	
	// 是否為二部圖的判斷
	bool Answer = true;
	for (int i = 1; i <= M; i++) {
		if (color[A[i]] == color[B[i]]) Answer = false;
	}
	if (Answer == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}