#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N;
int cost[501] = { 0 };  //�������� ���踦 ǥ���� �׷���
int entryDegree[101] = { 0 }; //�� ������ ���� ���� ���� 
bool visit[101];              //���� �湮 ǥ��


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int a;

	for (int i = 1; i <= N; ++i) {
		cin >> cost[i];
		entryDegree[i]++;  //b�� �������� ����

		while (1) {
			cin >> a;

			if (a == -1)
				break;


		}
	}

	return 0;
}