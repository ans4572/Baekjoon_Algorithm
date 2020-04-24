#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//���� ��Ÿ���� Ŭ����
class country {
public:
	int num;
	int gold, silver, bronze;
	int rank;

	country() {}

	country(int num, int gold, int silver, int bronze) {
		this->num = num;
		this->gold = gold;
		this->silver = silver;
		this->bronze = bronze;
		rank = 1;
	}

	bool operator<(country B) {
		if (gold < B.gold)
			return true;
		else if (gold == B.gold) {
			if (silver < B.silver)
				return true;
			else if (silver == B.silver) {
				if (bronze < B.bronze)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
};

int main() {
	int N, K;
	cin >> N >> K;

	int n, g, s, b; //num, gold, silver, bronze
	vector<country> arr;
	for (int i = 0; i < N; ++i) {
		cin >> n >> g >> s >> b;
		arr.push_back(country(n, g, s, b));
	}

	//�� ���󸶴� ������ �ű�� �ݺ���
	//2�� �ݺ����� ���鼭 ���� ���(i)���� �� ���(j)�� �۴ٸ�
	//i�� ��ŷ ����
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i] < arr[j])
				arr[i].rank++;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (arr[i].num == K) {
			cout << arr[i].rank << endl;
			break;
		}
	}

	return 0;
}