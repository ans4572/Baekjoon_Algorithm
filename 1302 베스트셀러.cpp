#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	map<string, int> log;
	map<string, int>::iterator iter;

	string input;
	for (int i = 0; i < n; ++i) {
		cin >> input;

		iter = log.find(input);
		if (iter == log.end()) {
			log.insert(make_pair(input, 1));
		}
		else {
			iter->second++;
		}
	}

	string bestSeller;
	int numOfBest = 0;
	for (iter = log.begin(); iter != log.end(); ++iter) {
		if (iter->second > numOfBest) {
			numOfBest = iter->second;
			bestSeller = iter->first;
		}
		else if (iter->second == numOfBest) {
			if (iter->first < bestSeller) {
				bestSeller = iter->first;
			}
		}
	}

	cout << bestSeller << endl;

	return 0;
}