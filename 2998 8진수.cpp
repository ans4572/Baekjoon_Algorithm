#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string input;
	cin >> input;

	if (input.length() % 3 == 1)
		input = "00" + input;
	else if (input.length() % 3 == 2) {
		input = "0" + input;
	}

	int index = 0;
	while (index < input.length()) {
		string temp = "";
		temp = input.substr(index,3);

		if (temp == "000") cout << '0';
		else if (temp == "001") cout << '1';
		else if (temp == "010") cout << '2';
		else if (temp == "011") cout << '3';
		else if (temp == "100") cout << '4';
		else if (temp == "101") cout << '5';
		else if (temp == "110") cout << '6';
		else if (temp == "111") cout << '7';

		index += 3;
	}

	return 0;
}