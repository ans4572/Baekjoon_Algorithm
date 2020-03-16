#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int *w = new int[N];
	int *h = new int[N];
	int *rank = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> w[i] >> h[i];
		rank[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			else {
				if (w[i] < w[j] && h[i] < h[j]) {
					rank[i]++;
				}
			}
		}
		cout << rank[i] << " ";
	}
	cout << endl;

	return 0;
}