#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int mushroom[10];
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		cin >> mushroom[i];
	}

	for (int i = 0; i < 10; ++i) {
		sum += mushroom[i];
		if (sum >= 100) {
			//마지막 버섯 전에 100을 넘겻다면
			//i 이전까지의 합과 i까지의 합을 각각 100과 비교하여
			//더 작은 격차를 구하여 출력한다.
			if ((100 - (sum - mushroom[i])) < sum - 100)
				cout << sum - mushroom[i] << endl;
			else
				cout << sum << endl;
			return 0;
		}
	}

	//100을 못 넘긴 경우
	cout << sum << endl;

	return 0;
}