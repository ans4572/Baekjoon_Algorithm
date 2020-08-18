#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string N;
	cin >> N;

	vector<char> num;
	for (int i = 0; i < N.length(); ++i)
		num.push_back(N[i]);

	sort(num.begin(), num.end(), greater<int>());

	//30의 배수가 되기 위해서는 조건이 2가지가 있다
	//1. 일의 자리 숫자는 반드시 0이여야 한다.
	//2. 모든 자리 숫자의 합은 3의 배수이여야 한다.

	//모든 자리 숫자의 합 구하기
	int sum = 0;
	for (int i = 0; i < N.length(); ++i) {
		sum += (N[i] - '0');
	}

	//일의 자리가 0인지와 sum이 3의 배수인지 확인
	if (num[N.length() - 1] == '0' && (sum % 3 == 0)) {
		for (int i = 0; i < num.size(); ++i)
			cout << num[i];
	}
	else
		cout << -1 << endl;

	return 0;
}