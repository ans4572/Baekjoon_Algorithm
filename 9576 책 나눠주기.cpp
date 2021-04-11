#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int T, N, M;

class Book {
public:
	int start;
	int end;

	Book() {}

	Book(int start, int end) {
		this->start = start;
		this->end = end;
	}

	//end를 기준으로 우선 정렬 후 같은 경우 start를 기준으로 정렬
	bool operator < (const Book& b) {
		if (this->end < b.end)
			return true;
		else if (this->end == b.end && this->start < b.start)
			return true;
		else return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	int a, b;
	for (int testCase = 0; testCase < T; ++testCase) {
		cin >> N >> M;

		vector<Book> arr(M);
		vector<bool> visit(N + 1);

		for (int i = 0; i < M; ++i) {
			cin >> a >> b;
			arr[i] = Book(a, b);
		}

		sort(arr.begin(), arr.end()); 
		int ans = 0;
		
		for (int i = 0; i < M; ++i) {
			//start부터 end까지 비어있는 곳 찾기
			for (int j = arr[i].start; j <= arr[i].end; ++j) {
				if (!visit[j]) {
					visit[j] = true;
					ans++;
					break;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}