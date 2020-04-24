#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N, K;
vector<string> made;    //���� ���� �����ϴ� �迭
vector<string> card;    //ī�� �����ϴ� �迭
string choice[4];       //�������� ���õ� ���� �ִ� �迭

//���� made�� �̹� num�� �����ϴ��� �Ǻ��ϴ� �Լ�
bool isExist(string num) {
	for (int i = 0; i < made.size(); ++i) {
		if (made[i].compare(num) == 0)
			return true;
	}

	return false;
}

//������ Ȱ���Ͽ� ���� �� �ִ� ���� ã�Ƽ� �ߺ����� �ʴ´ٸ� makeNum�� �߰��ϴ� �Լ�
void DFS(int count, int n, vector<bool> pick) {
	pick[n] = true;
	choice[count] = card[n];
	if (count == K-1) {
		string makeNum = "";
		for (int i = 0; i < K; ++i) {
			makeNum.append(choice[i]);
		}
		//�ߺ��Ǵ��� �Ǻ�
		if (!isExist(makeNum))
			made.push_back(makeNum);
		return;
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (pick[i] == false) {
				DFS(count + 1, i, pick);
			}
		}
	}
}

int main() {
	cin >> N >> K;

	string t = "";
	for (int i = 0; i < N; ++i) {
		cin >> t;
		card.push_back(t);
	}

	vector<bool> pick(10);
	for (int i = 0; i < N; ++i)
		DFS(0, i, pick);

	int ans = made.size();
	cout << ans << endl;

	return 0;
}