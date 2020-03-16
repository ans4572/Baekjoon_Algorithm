#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int day,count = 0,tmp;
	cin >> day;
	for (int i = 0; i < 5; ++i) {
		cin >> tmp;
		if (tmp == day)
			count++;
	}

	cout << count << endl;

	return 0;
}