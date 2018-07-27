#include<iostream>

using namespace std;

typedef struct Count {	// 0과 1이 각각 몇 번 출력 되는지 Count
	int zero = 0;
	int one = 0;
};

Count dp[41];	// N은 40보다 작거나 같은 자연수 또는 0

Count fibonacci(int n);
void init(int n);

int main() {

	int t;	// 테스트 케이스
	int n;	// 피보나치 수
	cin >> t;

	for (int i = 0; i < t; i++) {

		cin >> n;	// 피보나치 수 만큼

		init(n);	// count zero 값에 -1을 할당

		Count count = fibonacci(n);	// 계산된 fibonacci 값을 count 객체에 할당

		cout << count.zero << " " << count.one << endl;
	}

	return 0;
}

Count fibonacci(int n)
{
	if (dp[n].zero != -1) {	// 입력된 n의 값에 해당하는 zero가 -1이 아니라면
		return dp[n];	// 배열의 n번째 까지 해당하는 값 반환
	}
	// zero가 -1인 경우만 fibonacci가 적용됨
	Count c;
	if (n == 0) {
		c.zero += 1;
		c.one += 0;
	}
	else if (n == 1) {
		c.zero += 0;
		c.one += 1;
	}
	else {
		Count fibo1 = fibonacci(n - 1);	// 첫 번째 값
		Count fibo2 = fibonacci(n - 2);	// 두 번째 값

		c.zero += fibo1.zero;
		c.zero += fibo2.zero;

		c.one += fibo1.one;
		c.one += fibo2.one;
	}
	dp[n] = c;	// 동적으로 제한 된 배열만큼 할당
	return c;
}

void init(int n) {	// n에 입력된 값까지 zero에 -1 할당
	for (int i = 0; i <= n; i++) {
		dp[i].zero = -1;
	}
}