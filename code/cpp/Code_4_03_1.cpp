#include <iostream>
using namespace std;

int main() {
	double r = 2.0; // 因為欲求√2
	double a = 2.0; // 將初始值任意設定為2.0

	for (int i = 1; i <= 5; i++) {
		// 求點(a, f(a)) 的　x 座標及　y 座標
		double zahyou_x = a;
		double zahyou_y = a * a;

		// 求切線的方程式[ 設為y=(sessen_a)x+sessen_b]
		double sessen_a = 2.0 * zahyou_x;
		double sessen_b = zahyou_y - sessen_a * zahyou_x;

		// 求下一個a 的值next_a
		double next_a = (r - sessen_b) / sessen_a;
		printf("Step #%d: a = %.12lf -> %.12lf\n", i, a, next_a);
		a = next_a;
	}
	return 0;
}
