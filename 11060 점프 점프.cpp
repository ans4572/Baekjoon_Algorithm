#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int arr[1001];
int dy[1000];   //dy[n]: n까지 최소 몇 번 만에 갈 수 있는지

int main() {
	int N;
	cin >> N;

	//N이 1인 경우
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < N; ++i) {
		scanf("%d", &arr[i]);
	}

	dy[0] = 0;

	for (int i = 0; i < N - 1; ++i) {
		if (i != 0 && dy[i] == 0) continue;  //도달을 못하는 경우
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