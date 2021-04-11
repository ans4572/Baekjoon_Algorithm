#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

bool road[101][101][2];       //road[x][y][n]: n = 0 => (x,y-1) to (x,y) possible
							  //               n = 1 => (x-1,y) to (x,y) possible 

vector<vector<long long> > dy(101, vector<long long>(101, -1));

long long update(int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	if (dy[x][y] != -1)
		return dy[x][y];

	dy[x][y] = 0;
	if (road[x][y][0])
		dy[x][y] += update(x, y - 1);
	if (road[x][y][1])
		dy[x][y] += update(x - 1, y);

	return dy[x][y];
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	memset(road, true, sizeof(road));

	int a, b, c, d;
	for (int i = 0; i < K; ++i) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a == c)
			road[a][max(b, d)][0] = false;
		if (b == d)
			road[max(a, c)][b][1] = false;
	}

	dy[0][0] = 1;

	update(N, M);

	cout << dy[N][M] << "\n";

	return 0;
}