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

	int R, H;  //R: 가로, H: 세로
	cin >> R >> H;

	int N, dir, dis, Xdir, Xdis;  //N: 상점 개수, dir: 위치, dis: 거리, Xdir: 동근위치, Xdis: 동근거리  
	vector<pair<int, int> > v;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> dir >> dis;

		v.push_back(make_pair(dir, dis));
	}

	cin >> Xdir >> Xdis;  //동근 위치

	long long ans = 0;

	for (int i = 0; i < v.size(); ++i) {
		if (v[i].first == Xdir) {
			ans += abs(Xdis - v[i].second);
		}
		else {
			//상점과 동근의 위치가 북 or 남 으로만 있는 경우
			if (v[i].first <= 2 && Xdir <= 2) {
				ans += min(v[i].second + Xdis, (R - v[i].second) + (R - Xdis)) + H;
			}
			//상점과 동근의 위치가 동 or 서 로만 있는 경우
			else if (v[i].first > 2 && Xdir > 2) {
				ans += min(v[i].second + Xdis, (H - v[i].second) + (H - Xdis)) + R;
			}
			else {
				//4가지 케이스에 대해 최단 거리 구해서 더해주기
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