#include <string>
#include <iostream>
using namespace std;

// 用盧卡斯定理計算 ncr mod 3
int ncr(int x, int y) {
	if (x < 3 && y < 3) {
		if (x < y) return 0;
		if (x == 2 && y == 1) return 2;
		return 1;
	}
	return ncr(x / 3, y / 3) * ncr(x % 3, y % 3) % 3;
}

int main() {
	// 輸入
	int N; string C;
	cin >> N >> C;
	
	// 求出答案
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int code = -1;
		if (C[i] == 'B') code = 0;
		if (C[i] == 'W') code = 1;
		if (C[i] == 'R') code = 2;
		answer += code * ncr(N - 1, i);
		answer %= 3;
	}
	
	// 將答案乘以 (-1)^(N-1) 
	if (N % 2 == 0) {
		answer = (3 - answer) % 3;
	}
	
	// 輸出答案（"BWR" 的第 answer 個字母）
	cout << "BWR"[answer] << endl;
	
	return 0;
}