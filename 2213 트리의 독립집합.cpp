#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>

using namespace std;

bool visit[10001];

class Node {
public:
	int num;
	vector<int> conn;

	Node() {}
	Node(int num) {
		this->num = num;
	}
};

void DFS(int n) {

}

int main() {
	int N;
	cin >> N;

	vector<Node> tree(N + 1);

	int input;
	for (int i = 1; i <= N; ++i) {
		cin >> input;
		tree[i].num = input;
	}

	int a, b;
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;
		tree[a].conn.push_back(b);
		tree[b].conn.push_back(a);
	}



	return 0;
}