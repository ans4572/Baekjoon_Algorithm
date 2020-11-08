#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<pair<int,int> > jewelry(N);
	vector<int> bag(K);

	for (int i = 0; i < N; ++i) {
		scanf("%d %d", &jewelry[i].first, &jewelry[i].second);
	}

	for (int i = 0; i < K; ++i) {
		scanf("%d", &bag[i]);
	}

	sort(jewelry.begin(), jewelry.end());
	sort(bag.begin(), bag.end());

	long long sum = 0;
	priority_queue<int> pq;
	int j = 0;
	for (int i = 0; i < K; ++i) {
		//i��° ���濡 �� �� �ִ� �������� ���� pq�� �־��ֱ� 
		while (j < N && jewelry[j].first <= bag[i])
			pq.push(jewelry[j++].second);

		//pq�� ��Ʈ�� ���� ��� ������ �����ϹǷ� �����ְ� ���ֱ�
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		} 
	}

	cout << sum << endl;

	return 0;
}