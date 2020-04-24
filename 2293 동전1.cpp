#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K;

int main() {
	cin >> N >> K;
	vector<int> coin(N);
	int dy[10001] = { 0 };   //dy[i]: �ݾ� i���� ���� �� �ִ� ����� ��

	for (int i = 0; i < N; ++i) {
		cin >> coin[i];
	}

	/*
	�� ������ ���� j���� ���� i-1 ������ŭ ����ؼ�
	���� �� �ִ� ����� ���� �ݺ��ؼ� ���Ѵ�.
	ex) i = 0�϶� coin[0]���� ���� �� �ִ� ����� �� ���ϰ�
	    i = 1�϶� coin[0]�� coin[1]�� ���� �� �ִ� ����� �� ���Ѵ�.
		�̸� i = N-1���� �ݺ�
	*/
	dy[0] = 1;
	for (int i = 0; i < N ; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (j >= coin[i])
				dy[j] += dy[j - coin[i]];
		}
	}

	cout << dy[K] << endl;

	return 0;
}