#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	bool student[31] = { false };
	int tmp;
	for (int i = 1; i <= 28; ++i) {
		cin >> tmp;
		student[tmp] = true;
	}

	for (int i = 1; i <= 30; ++i) {
		if (student[i] == false)
			cout << i << endl;
	}

	return 0;
}