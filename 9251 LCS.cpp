#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int dy[1001][1001];  //dy[i][j]: 두 문자열의 길이가 각각 i일 때와 j일때의 최장 공통 길이.

int main() {
	string a, b;
	cin >> a;
	cin >> b;

	int ans = 0;
	//a를 기준으로 b를 하나씩 추가하면서 가장 긴 길이를 찾는다.
	for (int i = 1; i <= b.length(); ++i) {
		for (int j = 1; j <= a.length(); ++j) {
			//a의 문자와 b의 문자가 같은 경우, 왼쪽 대각선에서 +1을 더해준다.
			if (a[j - 1] == b[i - 1]) {
				dy[i][j] = dy[i - 1][j - 1] + 1;
			}
			//a의 문자와 b의 문자가 다른 경우, 왼쪽과 위쪽 중 큰 값을 대입한다.
			else {
				dy[i][j] = max(dy[i - 1][j], dy[i][j - 1]);
			}
			if (ans < dy[i][j])
				ans = dy[i][j];
		}
	}
	
	cout << ans << endl;

	return 0;
}