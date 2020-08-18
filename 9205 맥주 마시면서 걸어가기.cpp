#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int t, n;
bool possible;

class location {
public:
	int x, y;

	location(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {
	cin >> t;

	int hX, hY, sX, sY, rX, rY;  //home ��ǥ, store ��ǥ, rock festival ��ǥ
	for (int tc = 1; tc <= t; ++tc) {
		cin >> n;
		vector<location> p;
		cin >> hX >> hY;
		p.push_back(location(hX, hY));
		for (int i = 0; i < n; ++i) {
			cin >> sX >> sY;
			p.push_back(location(sX, sY));
		}
		cin >> rX >> rY;
		p.push_back(location(rX, rY));

		//map�� boolŸ���� 2���� �迭�� ���� �� ������ �Ÿ��� ����Ͽ� 1000������ ��쿡�� ������ �Ѵ�.
		vector<vector<bool> > map(p.size(), vector<bool>(p.size(), false));

		for (int i = 0; i < p.size(); ++i) {
			for (int j = 0; j < p.size(); ++j) {
				if(abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y) <= 1000)
				map[i][j] = true;
			}
		}

		//�÷��̵� �ͼ� �˰��� Ȱ��
		for (int k = 0; k < p.size(); ++k) {
			for (int i = 0; i < p.size(); ++i) {
				for (int j = 0; j < p.size(); ++j) {
					if(map[i][k] == true && map[k][j] == true)
						map[i][j] = true;
				}
			}
		}

		if (map[0][p.size() - 1] == true)
			cout << "happy" << endl;
		else
			cout << "sad" << endl;
	}

	return 0;
}