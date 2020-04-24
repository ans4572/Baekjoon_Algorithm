#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> inversion;
	vector<int> arr;
	inversion.push_back(-1);
	arr.push_back(-1);

	int c;
	for (int i = 1; i <= N; ++i) {
		cin >> c;
		inversion.push_back(c);
	}

	int pos;
	for (int i = 1; i <= N; ++i) {
		if (inversion[i] == 0) {
			arr.push_back(i);
		}
		else {
			pos = arr.size();
			pos -= inversion[i];
			arr[pos] = i;
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}