#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> noListen(N);
	vector<string> noSee(M);
	vector<string> nono;

	for (int i = 0; i < N; ++i)
		cin >> noListen[i];
	for (int i = 0; i < M; ++i)
		cin >> noSee[i];

	//두 string 벡터를 사전순으로 정렬
	sort(noListen.begin(), noListen.end());
	sort(noSee.begin(), noSee.end());

	int p1 = 0, p2 = 0,count=0;
	while (1) {
		if (noListen[p1] > noSee[p2]) p2++;
		else if (noListen[p1] < noSee[p2]) p1++;
		else {
			nono.push_back(noListen[p1]);
			p1++;
			p2++;
			count++;
		}

		if (p1 == noListen.size() || p2 == noSee.size())
			break;
	}

	cout << count << endl;
	for (int i = 0; i < nono.size(); ++i) {
		cout << nono[i] << endl;
	}

	return 0;
}