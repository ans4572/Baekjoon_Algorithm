#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int upB, midB, lowB, coke, cider;
	int ans;
	cin >> upB;
	cin >> midB;
	cin >> lowB;
	cin >> coke;
	cin >> cider;
	
	ans = min(upB, min(midB, lowB)) + min(coke, cider) - 50;
	cout << ans << endl;

	return 0;
}