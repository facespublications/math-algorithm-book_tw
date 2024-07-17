#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

int main() {
	// 輸入
	double A, B, H, M;
	cin >> A >> B >> H >> M;
	
	// 求出座標
	double AngleH = 30.0 * H + 0.5 * M;
	double AngleM = 6.0 * M;
	double Hx = A * cos(AngleH * PI / 180.0), Hy = A * sin(AngleH * PI / 180.0);
	double Mx = B * cos(AngleM * PI / 180.0), My = B * sin(AngleM * PI / 180.0);
	
	// 求出距離 → 輸出
	double d = sqrt((Hx - Mx) * (Hx - Mx) + (Hy - My) * (Hy - My));
	printf("%.12lf\n", d);
	return 0;
}