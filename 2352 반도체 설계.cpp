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
	//lower_bound�� Ȱ���� LIS�˰���
	for (int i = 0; i < N; ++i) {
		cin >> port;

		int index = lower_bound(L.begin(), L.end(), port) - L.begin();

		if (index == L.size())  //���� �����ϴ� �͵麸�� ū ���� ���
			L.push_back(port);
		else   //��ġ�� ã�� ���
			L[index] = port;
	}

	cout << L.size() << endl;

	return 0;
}