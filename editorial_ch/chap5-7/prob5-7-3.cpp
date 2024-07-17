#include <iostream>
#include <algorithm>
using namespace std;
 
long long N, A[200009];
long long Answer = 0;
 
int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	// 排序（從程式碼 5.7.1 唯一增加的部分）
	sort(A + 1, A + N + 1);
	
	// 求出答案 → 輸出答案
	for (int i = 1; i <= N; i++) Answer += A[i] * (-N + 2LL * i - 1LL);
	cout << Answer << endl;
	return 0;
}