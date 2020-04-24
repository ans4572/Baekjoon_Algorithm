#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int N, W, H;
	cin >> N >> W >> H;

	int matches; //성냥
	for (int i = 0; i < N; ++i) {
		cin >> matches;

		//피타고라스 정리 활용
		if (matches <= sqrt(W*W + H * H))
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}

	return 0;
}