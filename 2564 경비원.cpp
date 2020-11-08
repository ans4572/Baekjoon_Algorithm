#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int R, H;  //R: ����, H: ����
	cin >> R >> H;

	int N, dir, dis, Xdir, Xdis;  //N: ���� ����, dir: ��ġ, dis: �Ÿ�, Xdir: ������ġ, Xdis: ���ٰŸ�  
	vector<pair<int, int> > v;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> dir >> dis;

		v.push_back(make_pair(dir, dis));
	}

	cin >> Xdir >> Xdis;  //���� ��ġ

	long long ans = 0;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first == Xdir) {
			ans += abs(Xdis - v[i].second);
		}
		else {
			//������ ������ ��ġ�� �� or �� ���θ� �ִ� ���
			if (v[i].first <= 2 && Xdir <= 2) {
				ans += min(v[i].second + Xdis, (R - v[i].second) + (R - Xdis)) + H;
			}
			//������ ������ ��ġ�� �� or �� �θ� �ִ� ���
			else if (v[i].first > 2 && Xdir > 2) {
				ans += min(v[i].second + Xdis, (H - v[i].second) + (H - Xdis)) + R;
			}
			else {
				//4���� ���̽��� ���� �ִ� �Ÿ� ���ؼ� �����ֱ�
				if (Xdir == 1 && v[i].first == 3 || Xdir == 3 && v[i].first == 1) {
					ans += Xdis + v[i].second;
				}
				else if (Xdir == 1 && v[i].first == 4) {
					ans += (R - Xdis) + v[i].second;
				}
				else if (Xdir == 2 && v[i].first == 3) {
					ans += Xdis + (H - v[i].second);
				}
				else if (Xdir == 2 && v[i].first == 4) {
					ans += (R - Xdis) + (H - v[i].second);
				}
				else if (Xdir == 3 && v[i].first == 2) {
					ans += (H - Xdis) + v[i].second;
				}
				else if (Xdir == 4 && v[i].first == 1) {
					ans += (R - v[i].second) + Xdis;
				}
				else if (Xdir == 4 && v[i].first == 2) {
					ans += (H - Xdis) + (R - v[i].second);
				}
			}
		}

	}

	cout << ans << endl;

	return 0;
}