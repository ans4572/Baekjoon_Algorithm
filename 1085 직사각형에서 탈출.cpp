#include<iostream>

using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int min = 1000;
	int d[4] = { x,y,h - y,w - x };
	//경계선까지이므로 상하좌우 중에 최소거리를 구하면 됨.
	for (int i = 0; i < 4; i++) {
		if (d[i] < min)
			min = d[i];
	}
	cout << min << endl;

	return 0;
}