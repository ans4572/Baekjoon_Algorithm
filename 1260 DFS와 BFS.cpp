#include<iostream>
#include<stack>
#include<queue>
#include<cstring>

using namespace std;

int graph[1001][1001] = { 0 };
bool visit[1001];
int N;

void DFS(stack<int> &s, int v)
{
	visit[v] = true;
	cout << v << " ";
	
	for (int i = 1; i <= N; ++i)
	{
		if (visit[i] == false && graph[v][i] == 1)
			DFS(s, i);
	}
}

void BFS(queue<int>& q, int v)
{
	visit[v] = true;
	q.push(v);

	while (!q.empty())
	{
		int pre = q.front();
		cout << pre << " ";
		q.pop();

		for (int i = 1; i <= N; ++i)
		{
			if (visit[i] == false && graph[pre][i] == 1)
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}
}

int main()
{
	int M, V;
	cin >> N >> M >> V;

	int x, y;
	for (int i = 0; i < M; ++i)
	{
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	stack<int> s;
	memset(visit, false, sizeof(visit));
	DFS(s, V);

	cout << endl;

	queue<int> q;
	memset(visit, false, sizeof(visit));
	BFS(q, V);

	return 0;
}