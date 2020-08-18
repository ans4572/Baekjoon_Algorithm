#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> count(10, 0);

	for (int i = 0; i < s.length(); ++i) {
		count[s[i] - '0']++;
	}

	//6이나 9인 경우 둘이 합하여 2로 나눈 값이 필요한 세트의 개수로 된다.
	//홀수인 경우를 고려하여 +1 을 해준다.
	count[6] = (count[6] + count[9] + 1) / 2;
	count[9] = count[6];

	//최대 값 찾기
	int maxNum = 0;
	for (int i = 0; i < 10; ++i) {
		if (count[maxNum] < count[i])
			maxNum = i;
	}

	cout << count[maxNum] << endl;

	return 0;
}