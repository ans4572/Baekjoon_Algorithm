#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> bundle;
	vector<char> op;

	//-�� �������� ��ȣ�� �ݰ� ���鼭 ��ȣ ���� ������ ������.  
	//ex. ( x + y ) - ( z ) - ( a + b + c)
	string num = "";
	int sum = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '-') {
			sum += stoi(num);
			bundle.push_back(sum);
			sum = 0;
			num = "";
		}
		else if (s[i] == '+') {
			sum += stoi(num);
			num = "";
		}
		else {
			num += s[i];
		}
	}
	sum += stoi(num);
	bundle.push_back(sum);

	int ans = bundle[0];
	for (int i = 1; i < bundle.size(); ++i) {
		ans -= bundle[i];
	}

	cout << ans << endl;

	return 0;
}