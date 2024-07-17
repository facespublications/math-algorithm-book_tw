#include <iostream>
using namespace std;
 
long long N, K;
long long V[20];
long long Answer = 0;
 
// 回傳最大公因數的函式
long long GCD(long long A, long long B) {
	if (B == 0) return A;
	return GCD(B, A % B);
}
 
// 回傳最小公倍數的函式
long long LCM(long long A, long long B) {
	return (A / GCD(A, B)) * B;
}
 
int main() {
	// 輸入
	cin >> N >> K;
	for (int i = 1; i <= K; i++) cin >> V[i];
 
	// 位元全搜尋
	for (int i = 1; i < (1 << K); i++) {
		long long cnt = 0; // 選擇數字的個數
		long long lcm = 1; // 最小公倍數
		for (int j = 0; j < K; j++) {
			if ((i & (1 << j)) != 0) {
				cnt += 1;
				lcm = LCM(lcm, V[j + 1]);
			}
		}
		long long num = N / lcm; // 數的個數，此數是被選擇的所有數字的倍數
		if (cnt % 2 == 1) Answer += num;
		if (cnt % 2 == 0) Answer -= num;
	}
 
	// 輸出
	cout << Answer << endl;
	return 0;
}