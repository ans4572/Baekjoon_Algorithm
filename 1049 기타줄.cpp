#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int p, s;
	int minPackage = 1000, minSingle = 1000;
	for (int i = 0; i < M; ++i) {
		cin >> p >> s;
		if (minPackage > p) minPackage = p;
		if (minSingle > s) minSingle = s;
	}
	
	//만약 패키지 최소 가격이 (낱개 최소 가격*6)보다 크거나 같은 경우
	//패키지로 살 필요 없이 낱개로 전부 사는 것이 최소값이다.
	if (minPackage >= minSingle * 6) 
		cout << N * minSingle << endl;
	else {
		int pNum = N / 6;  //package num
		int remain = N % 6;

		//(낱개 최소 가격*나머지)가 패키지 최소 가격보다 저렴한 경우
		if (minPackage >= minSingle * remain) 
			cout << pNum * minPackage + minSingle * remain << endl;
		//아니라면 패키지를 사는 것이 더 저렴하다.
		else {
			cout << (pNum + 1) * minPackage << endl;
		}
	}

	return 0;
}