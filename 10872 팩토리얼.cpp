#include<iostream>

using namespace std;

int fac(int n) {
	if (n == 0) //문제의 팩토리얼 범위는 0~12이므로 0도 고려해줘야함! 
		return 1;
	else if (n == 1)
		return 1;
	else
		return n * fac(n - 1);
}

int main() {
	int N;
	cin >> N;
	cout << fac(N) << endl;

	return 0;
}