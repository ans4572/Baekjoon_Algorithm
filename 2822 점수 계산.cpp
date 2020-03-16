#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int sum = 0;
	vector<int> score(9,0);
	vector<int> rank(9,0);

	for (int i = 1; i <= 8; ++i) {
		cin >> score[i];
		rank[i] = score[i];
	}

	sort(rank.begin(), rank.end());

	for (int i = 4; i <= 8; ++i) {
		sum += rank[i];
	}

	cout << sum << endl;

	for (int i = 1; i <= 8; ++i) {
		for (int j = 4; j <= 8; ++j) {
			if (rank[j] == score[i]) {
				cout << i << " ";
				break;
			}
		}
	}

	return 0;
}