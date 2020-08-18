#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	int p1 = 0, p2 = 0, sum = arr[0], count = 0;

	while (p2 < N) {
		//sum�� M���� �۰ų� ���ٸ� p2 ����
		if (sum <= M) {
			if (sum == M) count++;

			p2++;
			if (p2 == N) break;  //���� p2�� ���� �����ߴٸ� while�� ����

			sum += arr[p2];
		}
		//sum�� M���� ũ�ٸ� p1 ����
		else if (sum > M) {
			sum -= arr[p1];
			p1++;
		}
	}

	cout << count << endl;

	return 0;
}