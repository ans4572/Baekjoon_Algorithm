#include <iostream>
#include <algorithm>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int L, P, V, c = 1;

	while (true) {
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;
		int cal = (V / P) * L;
		if ((V % P) < L) cal += V % P;
		else cal += L;

		cout << "Case " << c++ << ": " << cal << endl;
	}

	return 0;
}