#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[1001];  //dy[n] ���� 1 ~ n���� ���� ���� 

int main() {
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		dy[i] = 1;
	}

	for (int i = 2; i <= N; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			//arr[i]�� ���ϴ� arr[j]���� Ŭ ��� 
			//�ش� dy[j] + 1 �� ���� dy[i]�� ���Ͽ� ū ������ �����Ѵ�.
			if (arr[i] > arr[j]) 
				dy[i] = max(dy[j] + 1, dy[i]);
		}
	}

	int max = 0;
	for (int i = 1; i <= N; ++i) {
		if (max < dy[i])
			max = dy[i];
	}

	cout << max << endl;

	return 0;
}