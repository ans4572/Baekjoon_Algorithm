#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int cityCnt[2001] = { 0 };   //도시별 박스 현황 저장

class info {
public:
	int lhs, rhs, cnt;   //시작, 도착, 박스 양

	info() {}
	info(int lhs, int rhs, int cnt) {
		this->lhs = lhs;
		this->rhs = rhs;
		this->cnt = cnt;
	}

	//1. 목적지순으로 정렬
	//2. 목적지가 같은 경우 출발지순으로 정렬을 위한 연산자 재정의
	bool operator < (info b) {
		if (this->rhs < b.rhs)
			return true;
		else if (this->rhs == b.rhs && this->lhs < b.lhs)
			return true;
		else 
			return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, C, M;
	cin >> N >> C >> M;

	vector<info> arr;
	
	int a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		arr.push_back(info(a, b, c));
	}

	sort(arr.begin(), arr.end());  //연산자 재정의로 인해 정렬

	int ans = 0;
	for (int i = 0; i < M; ++i) {
		int boxCnt = 0, leftCnt;

		//출발지와 목적지 사이의 존재하는 박스의 최대크기 탐색
		for (int j = arr[i].lhs; j < arr[i].rhs; ++j) {
			boxCnt = max(boxCnt, cityCnt[j]);
		}

		//더 추가할 수 있는 양을 구해 ans에 더해주기
		leftCnt = min(arr[i].cnt, C - boxCnt);
		ans += leftCnt;

		//도시별 박스 현황 갱신
		for (int j = arr[i].lhs; j < arr[i].rhs; ++j) {
			cityCnt[j] += leftCnt;
		}
	}

	cout << ans << endl;

	return 0;
}