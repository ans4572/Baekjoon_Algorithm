#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int L;
	double A, B, C, D;
	cin >> L;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> D;

	//ceil(): �ø� �Լ�
	int day = max(ceil(A/C),ceil(B/D)); 
	cout << L - day << endl;

	return 0;
}