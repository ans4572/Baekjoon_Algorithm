#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	long long x, y, dis, p;
	for (int i = 0; i < T; ++i) {
		p = 0;
		cin >> x >> y;
		dis = y - x;
		//3이하는 그 거리만큼 이동한다.
		if (dis <= 3) {
			cout << dis << endl;
			continue;
		}
		
		
		//제곱수(1,4,9,16..)에 따라 규칙적으로 최소 공간이동이 
		//증가하므로 이를 기준으로 할 p를 구한다.
		//거리:1 => 1, 거리:4 => 3, 거리:9 => 5, 거리:16 => 7 ...
		while (1) {
			if ((p + 1)*(p + 1) < dis)
				p++;
			else
				break;
		}

		//(p의 제곱 + (p+1)의 제곱 / 2)를 하면 사이 기준을 구할 수가 있다.
		//따라서 이 기준에 따라 작거나 같으면 p*2이 답이고, 크다면 p*2+1이 답이다.
		if (dis <= (p*p + (p + 1)*(p + 1)) / 2)
			cout << p * 2 << endl;
		else
			cout << p * 2 + 1 << endl;
	}

	return 0;
}