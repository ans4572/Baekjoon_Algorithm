#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
vector<char> arr;
char vowel[5] = { 'a','e','i','o','u' };
bool visit[15];

void code(int index, int vCount, int cCount) { //vVount: 모음 숫자, cCount: 자음 숫자
	if (vCount + cCount == L) {  
		if (vCount >= 1 && cCount >= 2) {  //조건에 맞는 경우
			for (int i = 0; i < arr.size(); ++i) {
				if (visit[i])
					cout << arr[i];
			}
			cout << '\n';
		}
		else
			return;
	}
	else {
		for (int i = index; i < C; ++i) {
			bool isVowel = false;
			for (int j = 0; j < 5; ++j) { //모음인지 확인
				if (arr[i] == vowel[j]) {
					isVowel = true;
					visit[i] = true;
					code(i + 1, vCount + 1, cCount);
					visit[i] = false;
				}
			}
			if (!isVowel) {  //모음이 아닌 경우
				visit[i] = true;
				code(i + 1, vCount, cCount + 1);
				visit[i] = false;
			}
		}
	}

	return;
}

int main() {
	cin >> L >> C;

	char input;
	for (int i = 0; i < C; ++i) {
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	code(0, 0, 0);

	return 0;
}