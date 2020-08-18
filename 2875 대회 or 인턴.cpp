#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	int groupNum, remain = 0;
	if (N >= M * 2)
		groupNum = M;
	else
		groupNum = N / 2;

	remain = N - (groupNum * 2) + M - groupNum;  //그룹결성 외 나머지 학생들의 수

	if (remain >= K)  //나머지 인원이 인턴쉽 참가 인원보다 많은 경우
		cout << groupNum << endl;
	else {   //나머지 인원이 인턴쉽 참가 인원보다 적은 경우
		int temp = K - remain;
		if (temp % 3 == 0) temp = temp / 3;
		else temp = (temp / 3) + 1;

		groupNum -= temp;
		if (groupNum <= 0)
			cout << 0 << endl;
		else
			cout << groupNum << endl;
	}

	return 0;
}