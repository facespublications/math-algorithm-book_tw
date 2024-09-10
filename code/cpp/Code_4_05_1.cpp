#include <iostream>
#include <vector>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009]; // G[i] 是與頂點 i 相鄰頂點的列表

int main() {
	// 輸入
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]); // 添加 B[i] 作為與頂點 A[i] 相鄰的頂點
		G[B[i]].push_back(A[i]); // 添加 A[i] 作為與頂點 B[i] 相鄰的頂點
	}

	// 輸出（G[i].size() 為與頂點i 相鄰頂點的列表的大小 = 度）
	for (int i = 1; i <= N; i++) {
		cout << i << ": {";
		for (int j = 0; j < G[i].size(); j++) {
			if (j >= 1) cout << ","; // 以逗號為區隔來輸出
			cout << G[i][j]; // G[i][j] 是與頂點　i 相鄰頂點之中的第j 個頂點
		}
		cout << "}" << endl;
	}
	return 0;
}
