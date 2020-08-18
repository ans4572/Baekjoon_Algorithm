#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
int p[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	vector<pair<int, int> > pillar;
	vector<int> lb;
	vector<int> memo;

	int a, b;
	for (int i = 0; i < N; ++i) {
		cin >> a >> b;
		pillar.push_back({ a,b });
	}

	sort(pillar.begin(), pillar.end());

	//Lower_Bound를 활용한 LIS알고리즘
	lb.push_back(pillar[0].second);
	for (int i = 1; i < N; ++i) {
		if (lb.back() < pillar[i].second) {
			lb.push_back(pillar[i].second);
			p[i] = lb.size() - 1;
		}
		else {
			auto index = lower_bound(lb.begin(), lb.end(), pillar[i].second);
			*index = pillar[i].second;
			p[i] = index - lb.begin();
		}
	}

	int count = lb.size();
	cout << N - count << '\n';   //'\n'이 endl보다 훨씬 빠르다!
	count--;
	for (int i = N - 1; i >= 0; --i) {
		if (p[i] == count) {
			count--;
			continue;
		}
		memo.push_back(pillar[i].first);
	}

	for (int i = memo.size() - 1; i >= 0; --i) {
		cout << memo[i] << '\n';
	}

	return 0;
}