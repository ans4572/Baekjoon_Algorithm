#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int N, W, H;
	cin >> N >> W >> H;

	int matches; //����
	for (int i = 0; i < N; ++i) {
		cin >> matches;

		//��Ÿ��� ���� Ȱ��
		if (matches <= sqrt(W*W + H * H))
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	return 0;
}