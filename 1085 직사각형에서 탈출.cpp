#include<iostream>

using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int min = 1000;
	int d[4] = { x,y,h - y,w - x };
	//��輱�����̹Ƿ� �����¿� �߿� �ּҰŸ��� ���ϸ� ��.
	for (int i = 0; i < 4; i++) {
		if (d[i] < min)
			min = d[i];
	}
	cout << min << endl;

	return 0;
}