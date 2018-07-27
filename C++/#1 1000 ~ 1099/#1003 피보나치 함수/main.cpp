#include<iostream>

using namespace std;

typedef struct Count {	// 0�� 1�� ���� �� �� ��� �Ǵ��� Count
	int zero = 0;
	int one = 0;
};

Count dp[41];	// N�� 40���� �۰ų� ���� �ڿ��� �Ǵ� 0

Count fibonacci(int n);
void init(int n);

int main() {

	int t;	// �׽�Ʈ ���̽�
	int n;	// �Ǻ���ġ ��
	cin >> t;

	for (int i = 0; i < t; i++) {

		cin >> n;	// �Ǻ���ġ �� ��ŭ

		init(n);	// count zero ���� -1�� �Ҵ�

		Count count = fibonacci(n);	// ���� fibonacci ���� count ��ü�� �Ҵ�

		cout << count.zero << " " << count.one << endl;
	}

	return 0;
}

Count fibonacci(int n)
{
	if (dp[n].zero != -1) {	// �Էµ� n�� ���� �ش��ϴ� zero�� -1�� �ƴ϶��
		return dp[n];	// �迭�� n��° ���� �ش��ϴ� �� ��ȯ
	}
	// zero�� -1�� ��츸 fibonacci�� �����
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
		Count fibo1 = fibonacci(n - 1);	// ù ��° ��
		Count fibo2 = fibonacci(n - 2);	// �� ��° ��

		c.zero += fibo1.zero;
		c.zero += fibo2.zero;

		c.one += fibo1.one;
		c.one += fibo2.one;
	}
	dp[n] = c;	// �������� ���� �� �迭��ŭ �Ҵ�
	return c;
}

void init(int n) {	// n�� �Էµ� ������ zero�� -1 �Ҵ�
	for (int i = 0; i <= n; i++) {
		dp[i].zero = -1;
	}
}