#include <iostream>
#include <algorithm>
using namespace std;

int N, A[200009];

int main() {
	// 輸入（例如輸入了N=5、A[1]=3、A[2]=1、A[3]=4、A[4]=1,A[5]=5）
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 排序（因為要排序半開區間 [1, N+1) ，因此引數指定 A+1, A+N+1）
	// 藉由 sort 函式，將陣列的內容[3,1,4,1,5] 改寫為1,1,3,4,5]
	sort(A + 1, A + N + 1);

	// 輸出（按照1、1、3、4、5 的順序輸出）
	for (int i = 1; i <= N; i++) cout << A[i] << endl;
	return 0;
}
