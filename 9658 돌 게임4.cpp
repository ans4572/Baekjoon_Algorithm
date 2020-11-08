#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

int dy[1001];   //dy[i] = 1  => 상근이가 이기는 경우
				//      = -1 => 상근이가 지는 경우 

int main() {
	int N;
	cin >> N;

	dy[1] = -1;
	dy[2] = 1;
	dy[3] = -1;
	dy[4] = 1;

	for (int i = 5; i <= N; ++i) {
		if (dy[i - 1] == 1 && dy[i - 3] == 1 && dy[i - 4] == 1) {
			dy[i] = -1;
		}
		else
			dy[i] = 1;
	}

	if (dy[N] == 1) cout << "SK" << endl;
	else cout << "CY" << endl;

	return 0;
}