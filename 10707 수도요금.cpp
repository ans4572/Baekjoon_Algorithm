#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int A, B, C, D, P;
	int X, Y;

	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;
	cin >> P;

	X = P * A;
	
	//Y회사 요금 계산
	if (C >= P) 
		Y = B;
	else {
		Y = B + (P - C)*D;
	}

	if (X > Y)
		cout << Y << endl;
	else
		cout << X << endl;

	return 0;
}