#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	string s = "";
	vector<string> files(N);

	for (int i = 0; i < N; ++i) {
		cin >> files[i];
	}

	bool same = true;
	for (int i = 0; i < files[0].length(); ++i) {
		same = true;
		
		for (int j = 1; j < N; ++j) {
			if (files[0][i] != files[j][i]) {
				same = false;
				break;
			}
		}

		if (same == false) 
			s += "?";
		else
			s += files[0][i];
	}

	cout << s << endl;

	return 0;
}