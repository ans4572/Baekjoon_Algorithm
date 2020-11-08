#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int main() {
	int N, R, C;
	cin >> N >> R >> C;

	//계속 4분면으로 분할하여 찾기
	int r = pow(2, N) / 2;
	int c = r;
	int ans = 0;
	while (N >= 1) {
		int temp = pow(2, N - 1) / 2;  
		int skip = pow(4, N - 1);      //건너뛰는 수

		//1사분면
		if (R < r && C < c) {
			r -= temp;
			c -= temp;
		}
		//2사분면
		else if (R < r && C >= c) {
			r -= temp;
			c += temp;
			ans += skip;
		}
		//3사분면
		else if (R >= r && C < c) {
			r += temp;
			c -= temp;
			ans += skip * 2;
		}
		else {
			r += temp;
			c += temp;
			ans += skip * 3;
		}

		N--;
	}

	cout << ans << endl;

	return 0;
}