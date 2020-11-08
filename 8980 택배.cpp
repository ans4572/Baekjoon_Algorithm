#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int cityCnt[2001] = { 0 };   //���ú� �ڽ� ��Ȳ ����

class info {
public:
	int lhs, rhs, cnt;   //����, ����, �ڽ� ��

	info() {}
	info(int lhs, int rhs, int cnt) {
		this->lhs = lhs;
		this->rhs = rhs;
		this->cnt = cnt;
	}

	//1. ������������ ����
	//2. �������� ���� ��� ����������� ������ ���� ������ ������
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

	sort(arr.begin(), arr.end());  //������ �����Ƿ� ���� ����

	int ans = 0;
	for (int i = 0; i < M; ++i) {
		int boxCnt = 0, leftCnt;

		//������� ������ ������ �����ϴ� �ڽ��� �ִ�ũ�� Ž��
		for (int j = arr[i].lhs; j < arr[i].rhs; ++j) {
			boxCnt = max(boxCnt, cityCnt[j]);
		}

		//�� �߰��� �� �ִ� ���� ���� ans�� �����ֱ�
		leftCnt = min(arr[i].cnt, C - boxCnt);
		ans += leftCnt;

		//���ú� �ڽ� ��Ȳ ����
		for (int j = arr[i].lhs; j < arr[i].rhs; ++j) {
			cityCnt[j] += leftCnt;
		}
	}

	cout << ans << endl;

	return 0;
}