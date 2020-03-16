#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//�ּ� ����� Ȯ���ϱ� ���� �Լ�
int gcd(int a, int b) {
	int c;
	while (a%b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}

int main() {
	int A, B;
	cin >> A >> B;

	if (A == B) {
		cout << A << " " << B << endl;
		return 0;
	}

	vector<int> arr;

	for (int i = A; i <= B; i = i + A) {
		if (B%i == 0)
			arr.push_back(i);
	}

	int x = 0, y = 0;
	for (int i = 0; i < arr.size(); ++i) {
		for (int j = i + 1; j < arr.size(); ++j) {
			if ((arr[i] * arr[j] == A * B ) && gcd(arr[i],arr[j]) == A) {
				if (x == 0 && y == 0) {
					x = arr[i];
					y = arr[j];
				}
				//���� �� ���� ���
				if (arr[i] + arr[j] < x + y) {
					x = arr[i];
					y = arr[j];
				}
				break;
			}
		}
	}
	cout << x << " " << y << endl;

	return 0;
}