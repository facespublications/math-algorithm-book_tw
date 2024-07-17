#include <iostream>
#include <set>
using namespace std;
 
// 作為 f(m) 可能有的候選
// 關於 set 型態，請在網路上查詢！
set<long long> fm_cand;
 
// 回傳 m 的各個位數乘積的函式
long long product(long long m) {
	if (m == 0) {
		return 0;
	}
	else {
		long long ans = 1;
		while (m >= 1) {
			ans *= (m % 10);
			m /= 10;
		}
		return ans;
	}
}

void func(int digit, long long m) {
	// m 的位數為 11 位以下
	// 注：如果用 1 填充剩餘的位數，可以假設全部都是 11 位。
	if (digit == 11) {
		fm_cand.insert(product(m));
		return;
	}
	
	// 搜尋下一位
	// min_value 為 cur 的最後一位（為了使其單調遞增，下一位必須為比它大的值）
	int min_value = (m % 10);
	for (int i = min_value; i <= 9; i++) {
		// 10 * m + i 是在 m 之後附帶數字 i 的值
		func(digit + 1, 10 * m + i);
	}
}
 
int main() {
	// 列舉 f(m) 的候選
	func(0, 0);
 
	// 輸入
	long long N, B;
	cin >> N >> B;
 
	// 檢查是否為 m - f(m) == B
	long long Answer = 0;
	for (long long fm : fm_cand) {
		long long m = fm + B;
		long long prod_m = product(m);
		if (m - prod_m == B && m <= N) {
			Answer += 1;
		}
	}
 
	// 輸出
	cout << Answer << endl;
	return 0;
}