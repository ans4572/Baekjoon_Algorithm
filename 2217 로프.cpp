#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> rope(N);

	for (int i = 0; i < N; ++i) 
		cin >> rope[i];
	
	sort(rope.begin(), rope.end(), greater<int>());  //������������ ����

	int maxWeight = 0;

	//���ø� �� �ִ� ��ü�� �ִ� �߷��� 
	//(���� �۰� ��Ƽ�� ������ ����) * (��� ���� ����)
	//�̹Ƿ� �ݺ����� Ȱ���Ͽ� maxWeight�� ������ ������ ����ϸ� �ȴ�.
	for (int i = 0; i < N; ++i) {
		if (maxWeight < rope[i] * (i + 1)) 
			maxWeight = rope[i] * (i + 1);
	}

	cout << maxWeight << endl;

	return 0;
}