#include<iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int *num = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int max = 0;
	int sum;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = num[i] + num[j] + num[k];
				if (max == 0 && sum<=M) {
					max = sum;
				}
				if (sum <= M && sum > max)
					max = sum;
			}
		}
	}

	cout << max << endl;

	delete[] num;

	return 0;
}