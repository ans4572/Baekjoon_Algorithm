#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	//s 길이만큼 벡터 생성
	vector<string> array(s.length());

	for (int i = 0; i < s.length(); ++i) {
		array[i] = s.substr(i, s.length());
	}

	sort(array.begin(), array.end());

	for (int i = 0; i < s.length(); ++i) {
		cout << array[i] << endl;
	}

	return 0;
}