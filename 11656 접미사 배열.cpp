#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	//s ���̸�ŭ ���� ����
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