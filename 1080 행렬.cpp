#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

void reverseMatrix(int y,int x, vector<vector<bool> > &diff) {
	for (int i = y; i < y + 3; ++i) {
		for (int j = x; j < x + 3; ++j) {
			diff[i][j] = !diff[i][j];
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<char> > A(N, vector<char>(M));
	vector<vector<char> > B(N, vector<char>(M));
	vector<vector<bool> > diff(N, vector<bool>(M));
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> B[i][j];
			if (A[i][j] == B[i][j]) diff[i][j] = true;
			else diff[i][j] = false;
		}
	}

	int count = 0;
	for (int i = 0; i < N-2; ++i) {
		for (int j = 0; j < M-2; ++j) {
			if (diff[i][j] == false) {
				reverseMatrix(i, j, diff);
				count++;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (diff[i][j] == false) {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	cout << count << endl;

	return 0;
}