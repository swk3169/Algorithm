#include<iostream>
#include<math.h>

using namespace std;

double calc_distance(int x1, int y1, int x2, int y2);	// �Ÿ� ���
double calc_dot(int x1, int y1, int x2, int y2, int r1, int r2);	// ���� ���

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
	double result = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));	// ��Ÿ��� ����

	return result;
}

double calc_dot(int x1, int y1, int x2, int y2, int r1, int r2)
{
	double distance = calc_distance(x1, y1, x2, y2);	// �Ÿ� ���

	if (x1 == x2 && y1 == y2) {

		if (r1 == r2) {	// ��ġ�� ������ ���Ѵ��� ��� (�� ���� ������ ������ �����ִ� ���)
			return -1;
		}
		else {	// �� ���� ������ ���� ���
			return 0;
		}
	}
	else {

		if ((r1 + r2) > distance && abs(r1 - r2) < distance) {	// �� ���� ������ �ΰ��� ���
			return 2;
		}
		else if ((r1 + r2) == distance || abs(r1 - r2) == distance) {	// �� ���� ������ �Ѱ��� ���
			return 1;
		}
		else {
			return 0;
		}
	}
}