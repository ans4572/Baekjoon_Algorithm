#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

bool cmp(pair<string,bool> &a, pair<string, bool> &b) {
	return a.first > b.first;
}

int main() {
	int n;
	cin >> n;

	map<string,bool> log;
	map<string, bool>::iterator iter;

	string input;
	string action;
	for (int i = 0; i < n; ++i) {
		cin >> input >> action;

		if (action[0] == 'e') {
			iter = log.find(input);
			if (iter != log.end())
				log.find(input)->second = true;
			else
				log.insert(make_pair(input, true));
		}
		else {
			iter = log.find(input);
			if (iter != log.end())
				log.find(input)->second = false;
		}
	}

	vector<pair<string, bool>> vec(log.begin(), log.end());
	sort(vec.begin(), vec.end(), cmp);

	for (auto num : vec) {
		if (num.second == true) {
			cout << num.first << "\n";
		}
	}

	return 0;
}