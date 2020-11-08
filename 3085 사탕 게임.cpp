#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int N;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ans = 0;
vector<vector<char> > arr;

int candy() {
	int result = 1;

	//���� ī��Ʈ
	for (int i = 0; i < N; ++i) {
		int count = 1;
		for (int j = 0; j < N - 1; ++j) {
			if (arr[i][j] == arr[i][j + 1]) count++;
			else {
				result = max(result, count);
				count = 1;
			}
		}
		result = max(result, count);
	}

	//���� ī��Ʈ
	for (int i = 0; i < N; ++i) {
		int count = 1;
		for (int j = 0; j < N - 1; ++j) {
			if (arr[j][i] == arr[j + 1][i]) count++;
			else {
				result = max(result, count);
				count = 1;
			}
		}
		result = max(result, count);
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	arr.resize(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - 1; ++j) {
			//�� �� ����
			swap(arr[i][j], arr[i][j + 1]);
			ans = max(ans, candy());
			swap(arr[i][j], arr[i][j + 1]);  //�ٽ� ���� ��ġ��

			//�� �Ʒ� ����
			swap(arr[j][i], arr[j + 1][i]);
			ans = max(ans, candy());
			swap(arr[j][i], arr[j + 1][i]);  //�ٽ� ���� ��ġ��
		}
	}

	cout << ans << endl;

	return 0;
}
