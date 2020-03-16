#include<iostream>
#include<string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int x = 665; //반복문에서 x 증가를 하므로 665로 함
	for (int i = 0; i < N; i++) {
		x++;
		while (1) {
			string s = to_string(x); //x를 문자열로 바꿔서 조건문에 사용
			bool find = false; //반복문 2개를 빠져나가기 위해 사용
			for (int j = 0; j < s.length() - 2; j++) {
				if (s[j] == '6' && s[j + 1] == '6' && s[j + 2] == '6') {
					find = true;
					break;
				}
			}
			if (find == true) {
				break;
			}
			x++;
		}
	}

	cout << x << endl;

	return 0;
}