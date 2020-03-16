#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N,tmp;
	cin >> N;

	int notCount = 0;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		if (tmp == 0)
			notCount++;
	}

	if (notCount > (N / 2))
		cout << "Junhee is not cute!" << endl;
	else
		cout << "Junhee is cute!" << endl;

	return 0;
}