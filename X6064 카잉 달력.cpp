#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int M, N, x, y;

	for (int i = 0; i < T; i++) {
		int count = 0 , end = 0;
		int x_=1, y_=1;
		cin >> M >> N >> x >> y;
		while (x_ != x || y_ != y) {
			if (x_ >= M) {
				x_ = 1;
			}
			else {
				x_ = x_ + 1;
			}
			if (y_ >= N) {
				y_ = 1;
			}
			else {
				y_ = y_ + 1;
			}
			count++;
			if (x_ == x && y_ == y) {
				end = 1;
				break;
			}
			else if (x_ == M && y_ == N) {
				break;
			}
		}
		if (end == 1)
			cout << count + 1 << endl;
		else
			cout << -1 << endl;
	}
}