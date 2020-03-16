#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> vec;

	int n;

	for (int i = 0; i < N; ++i) {
		cin >> n;
		vec.push_back(n);
	}

	int min = 1000001;
	int max = -1000001;
	for (int i = 0; i < N; ++i) {
		if (vec[i] < min)
			min = vec[i];
		if (vec[i] > max)
			max = vec[i];
	}
	cout << min << " " << max << endl;

	return 0;
}