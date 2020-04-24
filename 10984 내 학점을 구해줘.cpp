#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int T, N;
	int C;
	double G;
	cin >> T;

	int C_sum;
	double G_sum;
	//학점 계산은 해당 학점 * 성적 /총 수강 학점
	//ex) (3학점 * 4.0 + ... ) / 18학점
	for (int i = 0; i < T; ++i) {
		C_sum = 0;
		G_sum = 0;
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> C >> G;
			C_sum += C;
			G_sum += G * C; 
		}

		cout << fixed;     //소숫점 아래 값을 고정하는 표현
		cout.precision(1); //소숫점 아래를 1로 고정

		cout << C_sum << " " << G_sum / C_sum << endl;
	}

	return 0;
}