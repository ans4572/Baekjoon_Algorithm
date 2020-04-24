#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dy[1001];  //dy[n]: 1~n���� ���� �κ� ���� �� ���� ū �� 

int main() {
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		dy[i] = arr[i];  //�ڱ� �ڽ��� ���� ū ������ �ʱ�ȭ 
	}

	//2���� N���� 
	//������ �ϳ��� arr[i]�� arr[j]�� ���ϸ鼭 arr[i]�� �� ũ�ٸ�
	//dy[i]�� dy[j] + arr[i]�� dy[i] �� �� ū ������ �����Ѵ�.
	for (int i = 2; i <= N; ++i) {
		for (int j = i - 1; j >= 1; --j) {
			if (arr[i] > arr[j])
				dy[i] = max(dy[j] + arr[i], dy[i]);
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