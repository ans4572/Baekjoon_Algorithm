#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string A, B;

int compare(int front, int end) {
	string temp = "";
	for (int i = 0; i < front; ++i) {
		temp += B[i];
	}
	temp += A;
	for (int i = B.length() - end; i < B.length(); ++i) {
		temp += B[i];
	}

	int count = 0;
	for (int i = 0; i < B.length(); ++i) {
		if (temp[i] != B[i])
			count++;
	}
	return count;
}

int main() {
	cin >> A >> B;

	int diff = B.length() - A.length();

	int front = diff, end = 0, ans = 51;

	//end�� diff���� �۰ų� ���� ������ bruteforce����
	while (end <= diff) {
		int c = compare(front, end);
		if (ans > c)
			ans = c;

		front--;
		end++;
	}

	cout << ans << endl;

	return 0;
}