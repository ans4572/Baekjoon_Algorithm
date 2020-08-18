#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

int L, R, C;
char building[31][31][31];
bool visit[31][31][31];

int dl[] = { 1,-1,0,0,0,0 };
int dr[] = { 0,0,1,-1,0,0 };
int dc[] = { 0,0,0,0,1,-1 };

class loc {
public:
	int l, r, c;
	int time;

	loc() {}
	loc(int l, int r, int c, int time) {
		this->l = l;
		this->r = r;
		this->c = c;
		this->time = time;
	}
};

bool inBuilding(int l, int r, int c) {
	return (l >= 0 && l < L&& r >= 0 && r < R&& c >= 0 && c < C);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	int nextL, nextR, nextC, ans;
	bool find;              //발견 여부 판단
	loc now;
	queue<loc> q;

	while (true) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) break;

		//초기화 작업
		memset(building, NULL, sizeof(building));
		memset(visit, false, sizeof(visit));  
		while (!q.empty()) q.pop();
		find = false;
		ans = -1;

		for (int l = 0; l < L; ++l) {
			for (int r = 0; r < R; ++r) {
				for (int c = 0; c < C; ++c) {
					cin>>building[l][r][c];

					if (building[l][r][c] == 'S')
						q.push(loc(l, r, c, 0));
				}
			}
		}

		while (!q.empty()) {
			now = q.front();
			q.pop();
			
			for (int i = 0; i < 6; ++i) {
				nextL = now.l + dl[i];
				nextR = now.r + dr[i];
				nextC = now.c + dc[i];

				if (building[nextL][nextR][nextC] == 'E') {
					ans = now.time + 1;
					find = true;
					break;
				}
				if (!visit[nextL][nextR][nextC] && building[nextL][nextR][nextC] == '.') {
					q.push(loc(nextL, nextR, nextC, now.time+1));
					visit[nextL][nextR][nextC] = true;
				}
			}

			if (find) break;
		}

		if (ans != -1) 
			cout << "Escaped in " << ans << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}

	return 0;
}