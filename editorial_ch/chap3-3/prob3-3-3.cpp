#include <iostream>
using namespace std;

long long n, r;
long long Fact_n = 1;
long long Fact_r = 1;
long long Fact_nr = 1;

int main() {
	// 輸入
	cin >> n >> r;
	
	// 計算階乘
	for (int i = 1; i <= n; i++) Fact_n *= i;
	for (int i = 1; i <= r; i++) Fact_r *= i;
	for (int i = 1; i <= n - r; i++) Fact_nr *= i;
	
	// 輸出
	cout << Fact_n / (Fact_r * Fact_nr) << endl;
	return 0;
}