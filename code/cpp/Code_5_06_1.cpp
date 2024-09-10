#include <iostream>
using namespace std;

int A, B, Answer = 0;

// 求解小問題 t 的函式
bool shou_mondai(int t) {
	int cl = (A + t - 1) / t; // 將 A÷t 的小數點以下進位
	int cr = B / t; // 將　B÷t 的小數點以下捨去
	if (cr - cl >= 1) return true;
	return false;
}

int main() {
	cin >> A >> B;
	for (int i = 1; i <= B; i++) {
		if (shou_mondai(i) == true) Answer = i;
	}
	cout << Answer << endl;
	return 0;
}
