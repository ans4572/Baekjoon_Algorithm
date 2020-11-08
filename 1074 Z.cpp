#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int main() {
	int N, R, C;
	cin >> N >> R >> C;

	//��� 4�и����� �����Ͽ� ã��
	int r = pow(2, N) / 2;
	int c = r;
	int ans = 0;
	while (N >= 1) {
		int temp = pow(2, N - 1) / 2;  
		int skip = pow(4, N - 1);      //�ǳʶٴ� ��

		//1��и�
		if (R < r && C < c) {
			r -= temp;
			c -= temp;
		}
		//2��и�
		else if (R < r && C >= c) {
			r -= temp;
			c += temp;
			ans += skip;
		}
		//3��и�
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