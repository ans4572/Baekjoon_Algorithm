#include <iostream>
#include <algorithm>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int N, L;

	cin >> N >> L;
	
	vector<int> arr(N);

	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int count = 0, index = 0;
	while (index < N) {
		int num = arr[index++];
		if (index >= N) {
			count++;
			break;
		}

		for (int i = num + 1; i < num + L; ++i) {
			if (arr[index] <= i) {
				index++;
			}
		}
		count++;
	}

	cout << count << endl;

	return 0;
}