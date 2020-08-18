#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	string input;
	cin >> input;

	int ans = 0;
	stack<int> s;
	vector<int> raiser;

	//레이저들 시작 위치 찾기
	for (int i = 0; i < input.length() - 1; ++i) {
		if (input[i] == '(' && input[i + 1] == ')')
			raiser.push_back(i);
	}

	int barCount = 0; //반복문을 지나면서 현재 존재하는 긴 막대 개수
	int index = 0; //raiser배열 인덱스
	//반복문을 통해 만약 레이저를 만나면 쌓인 bar개수만큼 ans에 더해준다.
	for (int i = 0; i < input.length(); ++i) {
		if (index < raiser.size() && i == raiser[index]) {
			ans += barCount;
			index++;
			i++;
		}
		else {
			if (input[i] == '(') {
				barCount++;
			}
			//막대가 끝나므로 막대의 개수는 줄이고 ans는 하나 더해준다.
			else {
				barCount--;
				ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}