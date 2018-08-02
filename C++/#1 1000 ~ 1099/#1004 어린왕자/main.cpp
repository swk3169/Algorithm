#include <iostream>
#include <cmath>

using namespace std;

double distance(int x1, int y1, int x2, int y2);	// 거리 계산

int main() {
	int t;	// 테스트 케이스
	int planet;	// 행성 갯수
	int x1, y1, x2, y2;	// 출발점 (x1, y1)과 도착점 (x2, y2)
	int cx, cy, r;	// 행성 좌표, 반지름
	int cnt;	// 각 테스트 케이스에 대해 어린 왕자가 거쳐야 할 최소의 행성계 진입/이탈 회수
	double dist_with_start, dist_with_end;	// 출발점, 도착점

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
				// 시작점이나 도착점이 하나의 원 안에 있을 때
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));	// 피타고라스 정리
}