#include <iostream>
using namespace std;

int main() {
	// 輸入
	long long N;
	cin >> N;
	
	// 質因數分解（以空白區隔來輸出）
	bool flag = false;
	for (long long i = 2; i * i <= N; i++) {
		while (N % i == 0) {
			if (flag == true) cout << " ";
			flag = true;
			N /= i;
			cout << i;
		}
	}
	if (N >= 2) {
		if (flag == true) cout << " ";
		flag = true;
		cout << N;
	}
	cout << endl;
	return 0;
}