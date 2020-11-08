#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool visitOdd[500001];  //홀수초 방문 저장
bool visitEven[500001]; //짝수초 방문 저장

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	if (N == K) {
		cout << 0 << endl;
		return 0;
	}

	queue<pair<int,int> > q;  //first: 위치, second: 초

	bool find = false;
	int t = 0;
	q.push(make_pair(N,0));

	while (!q.empty()) {
		pair<int,int> now = q.front();
		q.pop();
		
		//동생 이동
		if (now.second == t) {
			t++;
			K += t;

			if (K > 500000) break;
		}

		if (now.first + 1 <= 500000) {
			if (t % 2 == 0 && !visitEven[now.first + 1]) {
				visitEven[now.first + 1] = true;
				q.push(make_pair(now.first + 1, now.second + 1));
			}
			else if (t % 2 == 1 && !visitOdd[now.first + 1]) {
				visitOdd[now.first + 1]  = true;
				q.push(make_pair(now.first + 1, now.second + 1));
			}
		}
		if (now.first - 1 >= 0) {
			if (t % 2 == 0 && !visitEven[now.first - 1]) {
				visitEven[now.first - 1] = true;
				q.push(make_pair(now.first - 1, now.second + 1));
			}
			else if (t % 2 == 1 && !visitOdd[now.first - 1]) {
				visitOdd[now.first - 1] = true;
				q.push(make_pair(now.first - 1, now.second + 1));
			}
		}
		if (now.first * 2 <= 500000) {
			if (t % 2 == 0 && !visitEven[now.first * 2]) {
				visitEven[now.first * 2] = true;
				q.push(make_pair(now.first * 2, now.second + 1));
			}
			else if (t % 2 == 1 && !visitOdd[now.first * 2]) {
				visitOdd[now.first * 2] = true;
				q.push(make_pair(now.first * 2, now.second + 1));
			}
		}

		if (t % 2 == 0 && visitEven[K]) {
			find = true;
			break;
		}
		else if (t % 2 == 1 && visitOdd[K]) {
			find = true;
			break;
		}
	}
	
	if (find)
		cout << t << endl;
	else
		cout << -1 << endl;

	return 0;
}