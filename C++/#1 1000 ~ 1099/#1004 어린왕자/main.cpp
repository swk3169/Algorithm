#include <iostream>
#include <cmath>

using namespace std;

double distance(int x1, int y1, int x2, int y2);	// �Ÿ� ���

int main() {
	int t;	// �׽�Ʈ ���̽�
	int planet;	// �༺ ����
	int x1, y1, x2, y2;	// ����� (x1, y1)�� ������ (x2, y2)
	int cx, cy, r;	// �༺ ��ǥ, ������
	int cnt;	// �� �׽�Ʈ ���̽��� ���� � ���ڰ� ���ľ� �� �ּ��� �༺�� ����/��Ż ȸ��
	double dist_with_start, dist_with_end;	// �����, ������

	cin >> t;
	for (int i = 0; i < t; ++i) {

		cin >> x1 >> y1 >> x2 >> y2;
		cin >> planet;
		cnt = 0;
		for (int j = 0; j < planet; ++j) {
			cin >> cx >> cy >> r;

			dist_with_start = distance(x1, y1, cx, cy);
			dist_with_end = distance(x2, y2, cx, cy);

			if (dist_with_start <= r || dist_with_end <= r) {
				// �������̳� �������� �ϳ��� �� �ȿ� ���� ��
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));	// ��Ÿ��� ����
}