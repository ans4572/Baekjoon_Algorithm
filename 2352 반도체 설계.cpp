#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, ans = 1;
	cin >> N;

	int port;
	vector<int> L;
	//lower_bound를 활용한 LIS알고리즘
	for (int i = 0; i < N; ++i) {
		cin >> port;

		int index = lower_bound(L.begin(), L.end(), port) - L.begin();

		if (index == L.size())  //현재 존재하는 것들보다 큰 값인 경우
			L.push_back(port);
		else   //위치를 찾은 경우
			L[index] = port;
	}

	cout << L.size() << endl;

	return 0;
}