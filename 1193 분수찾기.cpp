#include<iostream>

using namespace std;

int main() {
	int x;
	cin >> x;
	if (x == 1) {
		cout << "1/1" << endl;
	}
	else {
		int g = 2; //group
		int i = 1;
		//find group value 
		while (1) {
			if (i < x) {
				if (i != 1)
					g++;
				i += g;
			}
			else {
				break;
			}
		}
		//g�� ���� ¦��orȦ�� ���� �⺻ �м� ���°� �ö��� �������� ����
		if (g % 2 == 0) {
			//1+(x-(i-g+1) / g-(x-(i-g+1))
			cout << x - i + g << "/" << i - x + 1 << endl;
		}
		else {
			//g-(x-(i-g+1)) / 1+(x-(i-g+1))
			cout << i - x + 1 << "/" << x - i + g << endl;
		}
	}
}