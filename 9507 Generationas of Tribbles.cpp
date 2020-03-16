#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long dy[70]; 

long long koong(int n) {
	if (n <= 3)
		return dy[n];
	else {
		if (dy[n] != 0)
			return dy[n];
		else
			return dy[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
	}
}

int main() {
	int t,tmp;
	cin >> t;
	
	dy[0] = 1;
	dy[1] = 1;
	dy[2] = 2;
	dy[3] = 4;
	for (int i = 0; i < t; ++i) {
		cin >> tmp;
		cout<<koong(tmp)<<endl;
	}

	return 0;
}