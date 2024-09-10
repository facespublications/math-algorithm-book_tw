// 這個原始碼為將深度優先搜尋 (DFS) 使用了堆疊的實作例。
// 堆疊為可進行「在最上層堆積元素」、「查找堆積在最上層的元素」、「刪除堆積在最上層的元素」三種操作的資料結構。
// 深度優先搜尋的部分為將程式碼 4.5.3 的 queue 變更為 stack，以此為基礎撰寫。

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009];

int main() {
	// 輸入
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}

	// 深度優先搜尋的初始化
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	stack<int> S; // 定義堆疊 S 
	visited[1] = true;
	S.push(1); // S 追加 1

	// 深度優先搜尋
	while (!S.empty()) {
		int pos = S.top(); // 調查 S 的開頭
		S.pop(); // 取出 S 的開頭
		for (int nex : G[pos]) {
			if (visited[nex] == false) {
				visited[nex] = true;
				S.push(nex); // 追加 nex 至 S
			}
		}
	}

	// 判定是否連通（Answer=true 時為連通）
	bool Answer = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) Answer = false;
	}
	if (Answer == true) {
		cout << "The graph is connected." << endl;
	}
	else {
		cout << "The graph is not connected." << endl;
	}
	return 0;
}
