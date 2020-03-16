#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (a%b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return b;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int T;
	cin >> T;

	int A, B, ans;
	for (int i = 0; i < T; ++i) {
		cin >> A >> B;
		ans = lcm(A, B);
		cout << ans << endl;
	}

	return 0;
}

//arr[i]: i�� �������ٸ� �������� i�� Ƚ����ŭ �����ϴ� �迭
//ex) 18 => arr[2] = 1, arr[3] = 2�̴�. 
//�� arr�� �ϼ���Ű�� �Լ�
//void Division(int n, int *arr) {
//	for (int i = 2; i < n; ++i) {
//		while (n%i == 0) {
//			arr[i]++;
//			n /= i;
//		}
//	}
//	arr[n] = 1;
//	return;
//}


	//int A_Division[45000] = { 0 };
	//int B_Division[45000] = { 0 };

	//int A, B, ans;
	//for (int i = 0; i < T; ++i) {
	//	memset(A_Division, 0, sizeof(A_Division));
	//	memset(B_Division, 0, sizeof(B_Division));
	//	ans = 1;

	//	cin >> A >> B;

	//	if (A == 1)
	//		cout << B << endl;
	//	else if (B == 1)
	//		cout << A << endl;
	//	else if (A == B)
	//		cout << A << endl;
	//	else {
	//		Division(A, A_Division);
	//		Division(B, B_Division);

	//		for (int i = 2; i <= max(A, B); ++i) {
	//			//�� �� ���� ��� �н�
	//			if (A_Division[i] == 0 && B_Division[i] == 0)
	//				continue;
	//			//�ִ� ��� i�� �ִ� ������ �������� �� �信�ٰ� �����ش�.
	//			else {
	//				ans = ans * pow(i, max(A_Division[i], B_Division[i]));
	//			}
	//		}

	//		cout << ans << endl;
	//	}
	//}

	//return 0;