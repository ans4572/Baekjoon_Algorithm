#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> division;  //����� ������ �迭

	//�ݺ����� ���鼭 ������ �迭�� �ֱ�
	for (int i = 1; i <= N; ++i) {
		if (N % i == 0)
			division.push_back(i);
	}

	//���� ����� ������ ���ؾ��� K���� �������
	if (division.size() < K) {
		cout << 0 << endl;
	}
	else {
		cout << division[K - 1] << endl;
	}

	return 0;
}