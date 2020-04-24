#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int W_score, K_score;
	vector<int> W(10);
	vector<int> K(10);
	for (int i = 0; i < 10; ++i) {
		cin >> W[i];
	}
	sort(W.begin(), W.end());
	W_score = W[7] + W[8] + W[9];

	for (int i = 0; i < 10; ++i) {
		cin >> K[i];
	}
	sort(K.begin(), K.end());
	K_score = K[7] + K[8] + K[9];

	cout << W_score << " " << K_score << endl;

	return 0;
}