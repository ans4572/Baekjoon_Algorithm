#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	string A,B;
	char op;
	cin >> A;
	cin >> op;
	cin >> B;

	//+인 경우
	if (op == '+') {
		//A와 B가 같은 경우 첫번째 문자열을 2로 바꿔준다.
		//ex) 100 + 100 = 200
		if (A == B) {
			A[0] = '2';
			cout << A << endl;
		}
		//A와 B가 다른 경우 문자열 길이를 비교하여 더 적은 길이의 문자열은
		//더 큰 길이의 문자열에서 해당 인덱스를 1로 바꿔준다.
		else {
			if (A.length() > B.length()) {
				A[A.length() - B.length()] = '1';
				cout << A << endl;
			}
			else {
				B[B.length() - A.length()] = '1';
				cout << B << endl;
			}
		}
	}
	//곱셈인 경우
	else if (op == '*') {
		//10의 제곱들의 곱셈은 A,B의 제곱의 수를 더한 값이므로
		//ex) 100 * 1000 = 10^2 * 10^3 = 10^5
		//답의 길이는 A의 길이(3) + B의 길이(4) - 1을 한 후 이를 0으로 다 초기화 해준다.
		//ex) 100000의 길이는 3 + 4 - 1 =6
		vector<char> ans(A.length() + B.length() - 1,'0'); 
		ans[0] = '1';
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i];
	}

	return 0;
}