#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, A[100009], B[100009];
int dist[100009];
vector<int> G[100009];

int main() {
	// 輸入
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// 廣度優先搜尋的初始化（dist[i]=-1 時，為未到達的白色頂點）
	for (int i = 1; i <= N; i++) dist[i] = -1;
	queue<int> Q; // 定義佇列Q
	Q.push(1); dist[1] = 0; // 將 1 添加到 Q 中（操作 1）

	// 廣度優先搜尋
	while (!Q.empty()) {
		int pos = Q.front(); // 查看 Q 的開頭（操作2）
		Q.pop(); // 取出Q 的開頭（操作3）
		for (int i = 0; i < (int)G[pos].size(); i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q.push(nex); // 將　nex 添加到Q 中（操作 1）
			}
		}
	}

	// 輸出從頂點　1 到各頂點的最短距離
	for (int i = 1; i <= N; i++) cout << dist[i] << endl;
	return 0;
}
