#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// 輸入
int H, W;
int sx, sy, start; // 起點的座標 (sx, sy) 與頂點編號 sx*H+sy
int gx, gy, goal;  // 終點的座標 (gx, gy) 與頂點編號 gx*W+gy
char c[59][59];
 
// 圖、最短路徑
int dist[2509];
vector<int> G[2509];
 
int main() {
	// 輸入
	cin >> H >> W;
	cin >> sx >> sy; start = sx * W + sy;
	cin >> gx >> gy; goal = gx * W + gy;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}
	
	// 將橫向的邊 [(i, j) - (i, j+1)] 添加到圖中
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W - 1; j++) {
			int idx1 = i * W + j; // 頂點 (i, j) 的頂點編號
			int idx2 = i * W + (j+1); // 頂點 (i, j+1) 的頂點編號
			if (c[i][j] == '.' && c[i][j+1] == '.'){
				G[idx1].push_back(idx2);
				G[idx2].push_back(idx1);
			}
		}
	}
	
	// 將縱向的邊 [(i, j) - (i+1, j)] 添加到圖中
	for (int i = 1; i <= H - 1; i++) {
		for (int j = 1; j <= W; j++) {
			int idx1 = i * W + j; // 頂點 (i, j) 的頂點編號
			int idx2 = (i+1) * W + j; // 頂點 (i+1, j) 的頂點編號
			if (c[i][j] == '.' && c[i+1][j] == '.'){
				G[idx1].push_back(idx2);
				G[idx2].push_back(idx1);
			}
		}
	}
 
	// 廣度優先搜尋的初始化（dist[i]=-1 時，是未到達的白色頂點）
	for (int i = 1; i <= H * W; i++) dist[i] = -1;
	queue<int> Q; // 定義佇列 Q 
	Q.push(start); dist[start] = 0; // 於 Q 添加 1（操作 1）
 
	// 廣度優先搜尋
	while (!Q.empty()) {
		int pos = Q.front(); // 查看 Q 的開頭（操作 2）
		Q.pop(); // 取出 Q 的開頭（操作 3）
		for (int i = 0; i < (int)G[pos].size(); i++) {
			int nex = G[pos][i];
			if (dist[nex] == -1) {
				dist[nex] = dist[pos] + 1;
				Q.push(nex); // 於 Q 添加 nex（操作 1）
			}
		}
	}
 
	// 輸出答案
	cout << dist[goal] << endl;
	return 0;
}