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
	
	sort(rope.begin(), rope.end(), greater<int>());  //내림차순으로 정렬

	int maxWeight = 0;

	//들어올릴 수 있는 물체의 최대 중량은 
	//(가장 작게 버티는 로프의 무게) * (사용 로프 개수)
	//이므로 반복문을 활용하여 maxWeight가 증가할 때까지 계산하면 된다.
	for (int i = 0; i < N; ++i) {
		if (maxWeight < rope[i] * (i + 1)) 
			maxWeight = rope[i] * (i + 1);
	}

	cout << maxWeight << endl;

	return 0;
}