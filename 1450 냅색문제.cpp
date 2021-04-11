#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int N, C;
int arr[30];
vector<int> vec1, vec2;

//����� �� ������ ���Ϳ� �ֱ�
void DFS(int s, int e, int sum, int bucket) {
	//�� ū ���� �ʿ� ����
	if (sum > C) 
		return;
	
	if (s == e) {
		if (bucket == 1) 
			vec1.push_back(sum);
		else
			vec2.push_back(sum);
		return;
	}

	DFS(s + 1, e, sum, bucket);
	DFS(s + 1, e, sum + arr[s], bucket);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; ++i) 
		cin >> arr[i];

	DFS(0, N / 2, 0, 1);
	DFS(N / 2, N, 0, 2);
	sort(vec2.begin(), vec2.end());

	int ans = 0;
	for (int i = 0; i < vec1.size(); ++i) {
		ans += upper_bound(vec2.begin(), vec2.end(), C - vec1[i]) - vec2.begin();
	}

	cout << ans << "\n";

	return 0;
}