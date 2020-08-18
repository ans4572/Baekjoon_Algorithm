#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<bool> > student(N + 1, vector<bool>(N + 1, false));

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		student[a][b] = true;
	}

	//�ڱ� �ڽ� Ű�� �ƴϱ� true�� ó��
	for (int i = 1; i <= N; ++i)
		student[i][i] = true;

	//�÷��̵� �ͼ� �˰��� Ȱ��
	for (int k = 1; k <= N; ++k) {
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (student[i][k] == true && student[k][j] == true)
					student[i][j] = true;
			}
		}
	}

	//������� true�� ä���ش�.
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (student[i][j] == true)
				student[j][i] = true;
		}
	}

	//�׷��� �� �پ� �ݺ����� ���鼭 ���� true��� ������ �ڱⰡ ���° Ű��������
	//�� �� �����Ƿ� ī��Ʈ�� �����ش�.
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		bool isCount = true;
		for (int j = 1; j <= N; ++j) {
			if (student[i][j] == false) {
				isCount = false;
				break;
			}
		}
		if (isCount)
			ans++;
	}

	cout << ans << endl;

	return 0;
}