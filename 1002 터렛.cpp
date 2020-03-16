#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//sqrt는 루트, pow는 거듭제곱
		double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		if (x1 == x2 && y1 == y2 && r1 != r2) {
			cout << 0 << endl;
		}
		//두 원이 일치할 때
		else if (x1 == x2 && y1 == y2 && r1 == r2) {
			cout << -1 << endl;
		}
		//두 원이 내접하거나 외접할 때
		else if (pow(r1 + r2,2) == pow(d,2) || pow(r1 + d,2) == pow(r2,2) || pow(r2 + d,2) == pow(r1,2)) {
			cout << 1 << endl;
		}
		//두 원이 서로 떨어져 있고 만나지 않을 때와
		//한 원이 다른 원의 내부에 있고 두 원이 만나지 않을 때
		else if (r1 + r2 < d || r1 + d < r2 || r2 + d < r1) {
			cout << 0 << endl;
		}
		//나머지
		else {
			cout << 2 << endl;
		}
	}

	return 0;
}