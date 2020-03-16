#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> inversion(N+1);
	for (int i = 1; i <= N; ++i)
		cin >> inversion[i];

	vector<int> arr(N+1);
	
	int c,i,j;
	for (i = 1; i <= N; ++i) {
		c = inversion[i];
		for (j = i; j > i-c; --j) {
			arr[j] = arr[j-1];
		}
		arr[j] = i;
	}
	for (i = 1; i <= N; ++i)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}