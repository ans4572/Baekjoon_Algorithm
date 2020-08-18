#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class document {
public:
	int order;
	int important;

	document(int order, int important) {
		this->order = order;
		this->important = important;
	}
};

int printNum(int M, queue<document> q, vector<int> imp) {
	int order = -1, outCount = 0;

	sort(imp.begin(), imp.end(),greater<int>());  //������������ ����
	int index = 0;    //imp�� index

	while (order != M) {
		for (int i = 0; i < q.size(); ++i) {
			if (q.front().important == imp[index]) {  //���� ť�� ���� �߿䵵 �� ���� ū ���� ���� ���
				order = q.front().order;
				q.pop();
				index++;
				outCount++;
				break;
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}

	return outCount;
}

int main() {
	int T;
	int N, M;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M;
		vector<int> imp(N);  //�߿䵵 ���� ����
		queue<document> q;
		for (int i = 0; i < N; ++i) {
			cin >> imp[i];
			q.push(document(i, imp[i]));
		}
		
		cout << printNum(M, q, imp) <<endl;
	}

	return 0;
}