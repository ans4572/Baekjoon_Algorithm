#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int arr[1001];
int dy[1000];   //dy[n]: n���� �ּ� �� �� ���� �� �� �ִ���

int main() {
	int N;
	cin >> N;

	//N�� 1�� ���
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}

	dy[0] = 0;

	for (int i = 0; i < N - 1; ++i) {
		if (i != 0 && dy[i] == 0) continue;  //������ ���ϴ� ���
		for (int j = i + 1; j <= i + arr[i]; ++j) {
			if (dy[j] == 0 || dy[j] > dy[i] + 1) {
				dy[j] = dy[i] + 1;
			}
		}
	}

	if (dy[N - 1] != 0)
		cout << dy[N - 1] << endl;
	else
		cout << -1 << endl;

	return 0;
}