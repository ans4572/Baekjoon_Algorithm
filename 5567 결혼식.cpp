#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	int a, b;
	vector<vector<bool> > maps(N + 1, vector<bool>(N + 1, false));
	vector<bool> visit(N + 1, false); //�湮 Ȯ�� �迭
	vector<int> friends;              //������� ģ�� ���� �迭
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		maps[a][b] = true;
		maps[b][a] = true;
	}

	int count = 0; //�ʴ��� ��� ��
	
	//�켱 ������� ģ�� ���� �� ī��Ʈ �ϴ� �ݺ���
	for (int i = 2; i <= N; ++i) {
		if (maps[1][i] == true) {
			count++;
			visit[i] = true;
			friends.push_back(i);
		}
	}

	//ģ���� ģ�� ī��Ʈ
	for (int i = 0; i < friends.size(); ++i) {
		for (int j = 2; j <= N; ++j) {
			if (visit[j] == false && maps[friends[i]][j] == true) {
				visit[j] = true;
				count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}