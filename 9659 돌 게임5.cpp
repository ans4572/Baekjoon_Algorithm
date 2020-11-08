#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main() {
	string N;

	cin >> N;

	int lastNum = N[N.length() - 1] - '0';

	if (lastNum % 2 == 1) cout << "SK" << endl;
	else cout << "CY" << endl;

	return 0;
}