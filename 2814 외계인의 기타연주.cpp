#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, P;
	cin >> N >> P;

	stack<int> s[7];

	for (int i = 1; i <= 6; ++i)
		s[i].push(0);

	int ans = 0;
	int line, pret;
	for (int i = 0; i < N; ++i) {
		cin >> line >> pret;

		//�ش� ������ ���� ū ������ ���ο� �������� ���� ���
		if (s[line].top() < pret) {
			s[line].push(pret);
			ans++;
		}
		//�ش� ������ ���� ū ������ ���ο� �������� ū ���
		else if (s[line].top() > pret) {
			//�۰ų� ���� ������ pop����
			while(s[line].top() > pret) {
				s[line].pop();
				ans++;
			}

			//�� ���� ��� ���� �߰�
			if (s[line].top() < pret) {
				s[line].push(pret);
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}