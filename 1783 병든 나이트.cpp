#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int N, M;

int dx[4] = { 1,2,2,1 };
int dy[4] = { 2,1,-1,-2 };

int main() {
	cin >> N >> M;

	int ans;

	//N이나 M이 1이라면 이동 불가
	if (N == 1 || M == 1)
		cout << 1 << endl;
	//N이 2인 경우
	else if (N == 2) {
		if (M <= 8)
			cout << (M + 1) / 2;
		//M이 9이상인 경우
		else
			cout << 4 << endl;
	}
	//N이 3이상인 경우
	else {
		if (M <= 4)
			cout << M << endl;
		else if (M < 7)
			cout << 4 << endl;
		else if (M == 7)
			cout << 5 << endl;
		//한 번씩 다 사용하고 난 후 최대값은 2칸 위로, 1칸 오른쪽 / 2칸 아래로, 1칸 오른쪽을 반복하는 것이다.
		//따라서 4가지 다 사용 후 5칸에서 최대 (가로 길이 - 7)만큼 칸을 더 방문할 수 있다.
		else
			cout << 5 + (M - 7) << endl;
	}

	return 0;
}