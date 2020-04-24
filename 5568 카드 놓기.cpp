#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N, K;
vector<string> made;    //만든 숫자 저장하는 배열
vector<string> card;    //카드 저장하는 배열
string choice[4];       //순열에서 선택된 숫자 넣는 배열

//벡터 made에 이미 num이 존재하는지 판별하는 함수
bool isExist(string num) {
	for (int i = 0; i < made.size(); ++i) {
		if (made[i].compare(num) == 0)
			return true;
	}

	return false;
}

//순열을 활용하여 만들 수 있는 숫자 찾아서 중복되지 않는다면 makeNum에 추가하는 함수
void DFS(int count, int n, vector<bool> pick) {
	pick[n] = true;
	choice[count] = card[n];
	if (count == K-1) {
		string makeNum = "";
		for (int i = 0; i < K; ++i) {
			makeNum.append(choice[i]);
		}
		//중복되는지 판별
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