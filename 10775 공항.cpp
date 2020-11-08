#include <iostream>
#include <algorithm>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int gate[100001];

int Find(int x) {
	if (x == gate[x])
		return x;
	else {
		gate[x] = Find(gate[x]);
		return gate[x];
	}
}

void Union(int x,int y) {
	x = Find(x);
	y = Find(y);
	gate[y] = x;
}

int main() {
	int G, P;
	cin >> G >> P;
	 
	for (int i = 1; i <= G; ++i) gate[i] = i;

	int arr[100001];
	for (int i = 0; i < P; ++i) {
		scanf("%d",&arr[i]);
	}

	//union-find를 통해 연결을 하여 도킹할 수 있는 개수 파악
	int ans = 0;
	for (int i = 0; i < P; ++i) {
		int k = Find(arr[i]);
		if (k == 0) break;
		Union(k - 1, k);
		ans++;
	}

	cout << ans << endl;

	return 0;
}