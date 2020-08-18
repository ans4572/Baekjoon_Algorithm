#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> arr(N+1);
	vector<bool> visit(N + 1, false);

	for (int i = 1; i <= N; ++i) 
		cin >> arr[i];

	int index = 1, pos, move, bp = 1;  //bp: break point
	cout << 1 << " ";
	visit[1] = true;
	while (1) {
		move = 0;
		pos = index;

		if (arr[index] > 0) {
			while (move < arr[index]) {
				pos++;
				if (pos > N) pos = 1;
				if (!visit[pos]) move++;
			}
			visit[pos] = true;
			bp++;
			cout << pos << " ";
		}
		else {
			while (move > arr[index]) {
				pos--;
				if (pos < 1) pos = N;
				if (!visit[pos]) move--;
			}
			visit[pos] = true;
			bp++;
			cout << pos << " ";
		}

		index = pos;

		if (bp == N) break;
	}
	
	return 0;
}