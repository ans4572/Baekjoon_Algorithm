#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;

	int alphabet[26] = { 0 };  //알파벳 수 저장할 배열
	string tmp;
	bool play = false;  //플레이 가능한지 판별

	//N번만큼 반복문을 돌면서 문자열을 입력받고
	//선수 첫 글자 알파벳 배열 개수 증가 시키기
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		alphabet[tmp[0]-'a']++;
	}

	//알파벳 개수(26) 만큼 반복문을 돌면서
	//5명 이상이라면 해당 문자 출력하기.
	for (int i = 0; i < 26; ++i) {
		if (alphabet[i] >= 5) {
			play = true;
			cout << char(i + 'a');
		}
	}

	//경기를 못 뛸 경우
	if (play == false)
		cout << "PREDAJA" << endl;

	return 0;
}