#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dy[1000]; //�ش� �ݾ� �϶� ������ �ּҰ�

int main() {
	int money,change = 1000;
	cin >> money;
	change -= money;

	int coin[5] = { 5,10,50,100,500 }; //1���� �� ������ ���ε�

	for (int i = 0; i < 1000; ++i)
		dy[i] = i;
	
	for (int i = 0; i < 5; ++i) {
		for (int j = coin[i]; j < 1000; ++j) {
			dy[j] = min(dy[j], dy[j - coin[i]] + 1);
		}
	}

	cout << dy[change] << endl;

	return 0;
}