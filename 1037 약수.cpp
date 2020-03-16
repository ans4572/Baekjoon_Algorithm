#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	if (N == 1)
		cout << arr[0] * arr[0] << endl;
	else if (N == 2)
		cout << arr[0] * arr[1] << endl;
	else
		cout << arr[0] * arr[N - 1] << endl;
	
	return 0;
}