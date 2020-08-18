#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i) 
		cin >> arr[i];
	
	//lower_bound를 활용한 LIS알고리즘
	vector<int> lb;
	for (int i = 0; i < N; ++i) {
		int index = lower_bound(lb.begin(), lb.end(), arr[i]) - lb.begin();
		if (lb.size() == index) 
			lb.push_back(arr[i]);
		else 
			lb[index] = arr[i];
	}

	cout << N - lb.size() << endl;

	return 0;
}