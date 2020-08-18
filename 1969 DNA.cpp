#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

const char dna[4] = { 'A','C','G','T' };

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> DNAs(N);
	for (int i = 0; i < N; ++i)
		cin >> DNAs[i];
	
	//make s
	string s = "";
	int diff[4], max;     //A,C,G,T count
	int hd = 0;
	for (int i = 0; i < M; ++i) {
		memset(diff, 0, sizeof(diff));
		max = 0;
		for (int j = 0; j < N; ++j) {
			if (DNAs[j][i] == 'A') diff[0]++;
			if (DNAs[j][i] == 'C') diff[1]++;
			if (DNAs[j][i] == 'G') diff[2]++;
			if (DNAs[j][i] == 'T') diff[3]++;
		}

		for (int j = 1; j < 4; ++j) {
			if (diff[max] < diff[j])
				max = j;
		}

		s += dna[max];

		for (int j = 0; j < N; ++j) {
			if (dna[max] != DNAs[j][i])
				hd++;
		}
	}

	cout << s << endl << hd << endl;

	return 0;
}