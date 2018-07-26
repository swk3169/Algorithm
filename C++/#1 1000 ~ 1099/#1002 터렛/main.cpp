#include<iostream>
#include<math.h>

using namespace std;

double calc_distance(int x1, int y1, int x2, int y2);	// 거리 계산
double calc_dot(int x1, int y1, int x2, int y2, int r1, int r2);	// 접점 계산

int main() {

	int n, x1, y1, r1, x2, y2, r2;

	cin >> n;

	for (int i = 0; i < n; ++i) {

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		cout << calc_dot(x1, y1, x2, y2, r1, r2) << endl;
	}

	return 0;
}

double calc_distance(int x1, int y1, int x2, int y2)
{
	double result = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));	// 피타고라스 정리

	return result;
}

double calc_dot(int x1, int y1, int x2, int y2, int r1, int r2)
{
	double distance = calc_distance(x1, y1, x2, y2);	// 거리 계산

	if (x1 == x2 && y1 == y2) {

		if (r1 == r2) {	// 위치의 개수가 무한대인 경우 (각 원의 교점이 완전히 겹쳐있는 경우)
			return -1;
		}
		else {	// 각 원의 교점이 없는 경우
			return 0;
		}
	}
	else {

		if ((r1 + r2) > distance && abs(r1 - r2) < distance) {	// 각 원의 교점이 두개인 경우
			return 2;
		}
		else if ((r1 + r2) == distance || abs(r1 - r2) == distance) {	// 각 원의 교점이 한개인 경우
			return 1;
		}
		else {
			return 0;
		}
	}
}