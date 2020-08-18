#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Conference {
public:
	int start;
	int end;

	Conference() {}

	Conference(int start, int end) {
		this->start = start;
		this->end = end;
	}

	bool operator < (const Conference &b) {
		if (this->end < b.end)
			return true;
		else if (this->end == b.end && this->start < b.start)
			return true;
		else return false;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int ans = 0;

	vector<Conference> conference; //�� ȸ�� ����
	int s, f;
	for (int i = 0; i < N; ++i) {
		cin >> s >> f;
		conference.push_back(Conference(s,f));
	}

	sort(conference.begin(), conference.end());  //���� �ð��� ���� ������� ����

	//�ݺ����� ���鼭 ȸ�� �ð��� ª�� �͵��� ��󳽴�.
	int lastEnd = 0;
	for (int i = 0; i < N; ++i) {
		if (lastEnd <= conference[i].start) {
			lastEnd = conference[i].end;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}