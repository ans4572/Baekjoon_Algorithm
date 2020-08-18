#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
	int dRank;  //면접 순위
	int iRank;  //인터뷰 순위

	Person(int dRank, int iRank) {
		this->dRank = dRank;
		this->iRank = iRank;
	}

	bool operator < (const Person &b) {
		if (this->dRank < b.dRank) return true;
		else return false;
	}
};

int main() {
	int T;
	cin >> T;

	int N;
	int dRank, iRank; //서류 성적과 인터뷰 성적
	int ans;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		vector<Person> applicants;  //지원자

		for (int i = 0; i < N; ++i) {
			scanf("%d %d", &dRank, &iRank);
			applicants.push_back(Person(dRank,iRank));
		}

		sort(applicants.begin(), applicants.end());  //면접 순위 오름차순으로 정렬

		int mark = applicants[0].iRank;  //첫번째 인터뷰 순위를 기준으로 잡아서 진행
		ans = 1;
		//반복문을 돌면서 i번째 후보자의 인터뷰 점수가 기준점 순위보다 작은 경우
		//기준점 순위를 갱신하고 ans를 증가한다.
		for (int i = 1; i < N; ++i) {
			if (applicants[i].iRank < mark) {
				mark = applicants[i].iRank;
				ans++;
			}
		}

		cout << ans << endl;
	}

	return 0;
}