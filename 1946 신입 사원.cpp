#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
	int dRank;  //���� ����
	int iRank;  //���ͺ� ����

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
	int dRank, iRank; //���� ������ ���ͺ� ����
	int ans;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		vector<Person> applicants;  //������

		for (int i = 0; i < N; ++i) {
			scanf("%d %d", &dRank, &iRank);
			applicants.push_back(Person(dRank,iRank));
		}

		sort(applicants.begin(), applicants.end());  //���� ���� ������������ ����

		int mark = applicants[0].iRank;  //ù��° ���ͺ� ������ �������� ��Ƽ� ����
		ans = 1;
		//�ݺ����� ���鼭 i��° �ĺ����� ���ͺ� ������ ������ �������� ���� ���
		//������ ������ �����ϰ� ans�� �����Ѵ�.
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