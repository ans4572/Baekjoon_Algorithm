#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N + 1);
	vector<int> B(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> B[i];

	A[1] = B[1];
	cout << A[1] << " ";
	for (int i = 2; i <= N; ++i) {
		A[i] = B[i] * i - B[i - 1]*(i-1);
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}