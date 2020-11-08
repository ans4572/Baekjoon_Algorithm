#include <iostream>
#include <algorithm>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int N, s;
	cin >> N;

	int p[100001];
	long long sum = 0, minPrice = 1000000000;

	for (int i = 0; i < N - 1; i++)
		scanf("%d", &p[i]);

	for (int i = 0; i < N - 1; i++) {
		scanf("%d", &s);
		minPrice = minPrice > s ? s : minPrice;
		sum += minPrice * p[i];
	}
	cout << sum << endl;

	return 0;
}