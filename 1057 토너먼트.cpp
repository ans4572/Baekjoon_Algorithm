#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int N, K, I;
	cin >> N >> K >> I;

	int round = 1;
	while (true) {
		int nextK = (K + 1) / 2;
		int nextI = (I + 1) / 2;

		if (nextK == nextI) break;

		K = nextK;
		I = nextI;

		round++;
	}

	cout << round << endl;

	return 0;
}