#include <iostream>
#include <algorithm>
using namespace std;

long long N;
long long X[200009], Y[200009];

int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	
	// 將陣列排序
	sort(X + 1, X + N + 1);
	sort(Y + 1, Y + N + 1);
	
	// 部分 1 的答案（x座標的差的絕對值總和）
	long long Part1 = 0;
	for (int i = 1; i <= N; i++) Part1 += X[i] * (-N + 2LL * i - 1LL);
	
	// 部分 2 的答案（y 座標的差的絕對值總和）
	long long Part2 = 0;
	for (int i = 1; i <= N; i++) Part2 += Y[i] * (-N + 2LL * i - 1LL);
	
	// 輸出
	cout << Part1 + Part2 << endl;
	return 0;
}