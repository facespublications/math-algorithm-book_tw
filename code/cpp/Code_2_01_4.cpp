#include <iostream>
#include <string>
using namespace std;

int N;
string Answer = ""; // string 為字串型別

int main() {
	cin >> N; // 輸入部分
	while (N >= 1) {
		// N % 2 為 N 除以 2 的餘數（例如：N=13 時為1）
		// N / 2 為 N 除以 2 的值的整數部分（例如：N=13 時為6）
		if (N % 2 == 0) Answer = "0" + Answer;
		if (N % 2 == 1) Answer = "1" + Answer;
		N = N / 2;
	}
	cout << Answer << endl; // 輸出部分
	return 0;
}
