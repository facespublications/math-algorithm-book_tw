#include <iostream>
#include <algorithm>
using namespace std;
 
// Movie 型態
struct Movie {
	int l, r;
};
 
bool operator<(const Movie &a1, const Movie &a2) {
	if (a1.r < a2.r) return true;
	if (a1.r > a2.r) return false;
	if (a1.l < a2.l) return true;
	return false;
}
 
int N;
Movie A[300009];
int CurrentTime = 0; // 現在時間（最後所選電影的結束時間）
int Answer = 0; // 現在已看過的電影數
 
int main() {
	// 輸入
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i].l >> A[i].r;
	
	// 排序
	sort(A + 1, A + N + 1);
	
	// 持續選擇結束時間最早的電影
	for (int i = 1; i <= N; i++) {
		if (CurrentTime <= A[i].l) {
			CurrentTime = A[i].r;
			Answer += 1;
		}
	}
	
	// 輸出
	cout << Answer << endl;
	return 0;
}