#include<iostream>

using namespace std;

int main() {
	int A=0, B=0;
	while (1) {
		cin >> A >> B;
		if (!cin.eof())
			cout << A + B << endl;
		else
			break;
	}

	return 0;
}