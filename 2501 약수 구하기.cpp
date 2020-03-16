#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> division;  //약수를 저장할 배열

	//반복문을 돌면서 약수라면 배열에 넣기
	for (int i = 1; i <= N; ++i) {
		if (N % i == 0)
			division.push_back(i);
	}

	//만약 약수의 개수가 구해야할 K보다 작은경우
	if (division.size() < K) {
		cout << 0 << endl;
	}
	else {
		cout << division[K - 1] << endl;
	}

	return 0;
}