#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int dy[1000]; //해당 금액 일때 동전의 최소값

int main() {
	int money,change = 1000;
	cin >> money;
	change -= money;

	int coin[5] = { 5,10,50,100,500 }; //1엔을 뺀 나머지 코인들

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