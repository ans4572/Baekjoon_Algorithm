#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int d, n, m;
	cin >> d >> n >> m;

	vector<int> island(n);

	for (int i = 0; i < n; ++i) 
		cin >> island[i];

	sort(island.begin(), island.end());

	//mid = 12 Ω√¿€
	
	return 0;
}