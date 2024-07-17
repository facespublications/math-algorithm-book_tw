#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> G[100009];

int main() {
	// 輸入
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	
	// 求出答案
	int Answer = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 0; j < G[i].size(); j++) {
			// G[i][j] 是與頂點 i 鄰接的頂點中第 j+1 個
			if (G[i][j] < i) cnt += 1;
		}
		// 如果比自己小的鄰接頂點為 1 個的話，將 Answer 加 1
		if (cnt == 1) Answer += 1;
	}
	
	// 輸出
	cout << Answer << endl;
	return 0;
}