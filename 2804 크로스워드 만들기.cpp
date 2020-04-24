#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	string A, B;
	cin >> A >> B;

	int aNum, bNum;
	vector<vector<char> > arr(B.length(), vector<char>(A.length(), '.'));

	//공통 글자의 위치 찾기
	bool find = false;
	for (int i = 0; i < A.length(); ++i) {
		for (int j = 0; j < B.length(); ++j) {
			if (A[i] == B[j]) {
				aNum = i;
				bNum = j;
				find = true;
				break;
			}
		}
		if (find == true)
			break;
	}

	//arr에 A문자 넣기
	for (int i = 0; i < A.size(); ++i) {
		arr[bNum][i] = A[i];
	}

	//arr에 B문자 넣기
	for (int i = 0; i < B.size(); ++i) {
		arr[i][aNum] = B[i];
	}

	for (int i = 0; i < B.length(); ++i) {
		for (int j = 0; j < A.length(); ++j) {
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}