#include <iostream>
using namespace std;

long long cross(long long ax, long long ay, long long bx, long long by) {
	// 向量 (ax, ay) 與 (bx, by) 的外積大小
	return ax * by - ay * bx;
}

int main() {
	// 輸入
	long long X1, Y1, X2, Y2, X3, Y3, X4, Y4;
	cin >> X1 >> Y1; // 輸入點 A 的座標
	cin >> X2 >> Y2; // 輸入點 B 的座標
	cin >> X3 >> Y3; // 輸入點 C 的座標
	cin >> X4 >> Y4; // 輸入點 D 的座標
	
	// 計算 cross(AB, AC)
	long long ans1 = cross(X2-X1, Y2-Y1, X3-X1, Y3-Y1);
	long long ans2 = cross(X2-X1, Y2-Y1, X4-X1, Y4-Y1);
	long long ans3 = cross(X4-X3, Y4-Y3, X1-X3, Y1-Y3);
	long long ans4 = cross(X4-X3, Y4-Y3, X2-X3, Y2-Y3);
	
	// 全部排在一直線上時（邊角案例）
	if (ans1 == 0 && ans2 == 0 && ans3 == 0 && ans4 == 0) {
		// 將　A, B, C, D 視為數值（正確來說是 pair 型態）
		// 藉由適當的進行 swap ，可以假設 A<B, C<D
		// 如此，可以歸結成判斷區間是否重疊的問題（節末問題 2.5.6）
		pair<long long, long long> A = make_pair(X1, Y1);
		pair<long long, long long> B = make_pair(X2, Y2);
		pair<long long, long long> C = make_pair(X3, Y3);
		pair<long long, long long> D = make_pair(X4, Y4);
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);
		if (max(A, C) <= min(B, D)) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}
	
	// 並非如此時
	// IsAB: 線段 AB 是否將點 C, D 分開？
	// IsCD: 線段 CD 是否將點 A, B 分開？
	bool IsAB = false, IsCD = false;
	if (ans1 >= 0 && ans2 <= 0) IsAB = true;
	if (ans1 <= 0 && ans2 >= 0) IsAB = true;
	if (ans3 >= 0 && ans4 <= 0) IsCD = true;
	if (ans3 <= 0 && ans4 >= 0) IsCD = true;
	
	// 輸出答案
	if (IsAB == true && IsCD == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}