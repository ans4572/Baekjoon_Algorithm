#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

int main() {
	long long N;
	cin >> N;

	//SK CY SK SK SK SK CY ¸¦ ¹Ýº¹
	
	if (N % 7 == 2 || N % 7 == 0)
		cout << "CY" << endl;
	else 
		cout << "SK" << endl;

	return 0;
}