#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, ans_min = 1000000000, ans_max = -1000000000;
int arr[11], op[4];

void Cal(int n, int cal) {
	if (n == N) {
		if (ans_min > cal)
			ans_min = cal;
		if (ans_max < cal)
			ans_max = cal;
	}
	else {
		if (op[0] > 0) {
			op[0]--;
			Cal(n + 1, cal + arr[n]);
			op[0]++;
		}
		if (op[1] > 0) {
			op[1]--;
			Cal(n + 1, cal - arr[n]);
			op[1]++;
		}
		if (op[2] > 0) {
			op[2]--;
			Cal(n + 1, cal * arr[n]);
			op[2]++;
		}
		if (op[3] > 0) {
			op[3]--;
			Cal(n + 1, cal / arr[n]);
			op[3]++;
		}
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < 4; ++i)
		cin >> op[i];

	Cal(1, arr[0]);
	cout << ans_max << endl;
	cout << ans_min << endl;

	return 0;
}