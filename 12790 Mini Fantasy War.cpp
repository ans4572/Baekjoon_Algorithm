#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	int hp, mp, attack, defense;
	int cHp, cMp, cAttack, cDefense; //change
	int power;
	for (int i = 0; i < T; ++i) {
		cin >> hp >> mp >> attack >> defense >> cHp >> cMp >> cAttack >> cDefense;
		power = max(hp + cHp, 1) + 5 * (max(mp + cMp, 1)) + 2 * max(attack + cAttack, 0) + 2 * (defense + cDefense);
		cout << power << endl;
	}

	return 0;
}