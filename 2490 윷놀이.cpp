#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int zeroCount = 0;
	int tmp;
	for (int i = 0; i < 3; ++i) {
		zeroCount = 0;
		for (int j = 0; j < 4; ++j) {
			cin >> tmp;
			if (tmp == 0)
				zeroCount++;
		}
		if (zeroCount == 1)
			cout << "A" << endl;
		else if (zeroCount == 2)
			cout << "B" << endl;
		else if (zeroCount == 3)
			cout << "C" << endl;
		else if (zeroCount == 4)
			cout << "D" << endl;
		else
			cout << "E" << endl;
	}

	return 0;
}