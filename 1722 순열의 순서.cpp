#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long f[21]; //factorial

int main() {
	int N, choice;
	cin >> N;

	bool visit[21] = { false };  //사용한 숫자 확인
	vector<int> per(N + 1, 0);

	//팩토리얼 초기화
	f[0] = 1;
	for (int i = 1; i <= 20; ++i) {
		f[i] = f[i - 1] * i;
	}

	cin >> choice;

	if (choice == 1) {
		long long K;
		cin >> K;

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (visit[j] == true) //이미 사용한 숫자라면 패스
					continue;
				//남은 K가 f[N-i]보다 크다면 K를 줄여주고 반복문 계속 진행
				if (K > f[N - i]) {
						K -= f[N - i];
				}
				//작다면 해당 i번째 숫자는 j이고 방문표시 해준다.
				else {
					per[i] = j;
					visit[j] = true;
					break;
				}
			}
		}

		for (int i = 1; i <= N; ++i)
			cout << per[i] << " ";
		cout << endl;
	}
	else if (choice == 2) {
		long long count = 0;

		for (int i = 1; i <= N; ++i) {
			cin >> per[i];
		}

		for (int i = 1; i <= N; ++i) {
			//1부터 돌면서 per[i]보다 낮은 숫자라면 
			//N-i만큼의 팩토리얼을 더하므로써 skip을 한다.
			//후에 같아진다면 사용했다는 것을 표시하고 반복문을 빠져나온다.
			for (int j = 1; j <= N; ++j) {
				if (visit[j] == true)
					continue;
				if (j < per[i]) {
					count += f[N - i];
				}
				else {
					visit[j] = true;
					break;
				}
			}
		}
		cout << count + 1 << endl;
	}

	return 0;
}