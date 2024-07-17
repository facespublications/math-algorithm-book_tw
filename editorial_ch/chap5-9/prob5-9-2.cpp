#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
long long N;
long long A[100009], B[100009];
 
int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	
	// 排序
	sort(A + 1, A + N + 1);
	sort(B + 1, B + N + 1);
	
	// 求出答案
	long long Answer = 0;
	for (int i = 1; i <= N; i++) Answer += abs(A[i] - B[i]);
	cout << Answer << endl;
	return 0;
}