#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009]; // visited[pos]=false 時頂點 x 為白色，true時為灰色

void dfs(int pos) {
	visited[pos] = true;
	// 像for (inti : G[pos]) 這樣的寫法稱為「範圍 for 敘述」(APG4b 2.01 節)
	for (int i : G[pos]) {
		if (visited[i] == false) dfs(i);
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
	dfs(1);

	// 判定是否連通（Answer=true 時為連通）
	bool Answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) Answer = false;
	}
	if (Answer == true) cout << "The graph is connected." << endl;
	else cout << "The graph is not connected." << endl;
	return 0;
}
