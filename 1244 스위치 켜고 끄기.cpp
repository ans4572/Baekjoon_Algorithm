#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

int arr[101];

int main() {
	int N, M;
	cin >> N;

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &arr[i]);
	}

	cin >> M;

	int a, b;
	for (int i = 0; i < M; ++i) {
		scanf("%d %d", &a, &b);

		if (a == 1) {
			int t = b;
			while (t <= N) {
				arr[t] = !arr[t];
				t += b;
			}
		}
		else {
			int fp = b - 1, bp = b + 1;  //front point, back point
			arr[b] = !arr[b];

			while (fp > 0 && bp <= N) {
				if (arr[fp] == arr[bp]) {
					arr[fp] = !arr[fp];
					arr[bp] = !arr[bp];
					fp--;
					bp++;
				}
				else
					break;
			}
		}
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d ", arr[i]);

		if (i % 20 == 0)
			cout << "\n";
	}

	return 0;
}