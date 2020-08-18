#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int N;
int line[11];

int main() {
	cin >> N;

	//키가 1인 사람부터 순서대로 처리
	for (int i = 1; i <= N; ++i) {
		int left;
		cin >> left;

		//line 0번부터 들어갈 위치 탐색
		for (int j = 0; j < N; ++j) {
			//왼쪽에 더 이상 큰 수가 없고 자리가 비어있는 경우 넣기
			if (left == 0 && line[j] == 0) {
				line[j] = i;
				break;
			}
			//자리가 비어있지만 왼쪽에 더 큰 수가 존재하는 경우 건너뛰어야함
			else if(line[j] == 0)
				left--;
		}
	}

	for (int i = 0; i < N; ++i)
		cout << line[i] << " ";
	
	return 0;
}