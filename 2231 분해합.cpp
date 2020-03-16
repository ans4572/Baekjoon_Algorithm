#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int con = 0; //생성자 저장 변수
	for (int i = 1; i < N; i++) {
		int t = i; //i는 변경되면 안되므로 새로운 변수 선언
		int sum = t;
		int d;
		//각 자리수마다 더해주기
		for (int j = 5; j >= 0; j--) {
			d = pow(10, j);
			sum += t / d;
			t %= d;
		}
		//합과 N이 같을 때 생성자 저장하고 break
		if (sum == N) {
			con = i;
			break;
		}
	}
	cout << con << endl;

	return 0;
}