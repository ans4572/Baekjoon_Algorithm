#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int K;
int lotto[13]; 
int combi[6];  //조합 저장

//로또 조합 찾는 DFS함수
void DFS(int start, int count) {
	if (count == 6) {
		for (int i = 0; i < 6; i++) {
			cout << combi[i] << " ";    
		}
		cout << endl;
		return;
	}

	for (int i = start; i < K; i++) {    
		combi[count] = lotto[i];
		DFS(i + 1, count + 1);
	}

}

int main() {
	while (true) {         
		cin >> K;
		if (K == 0)
			break;

		for (int i = 0; i < K; i++) {
			cin >> lotto[i];
		}

		DFS(0, 0);
		cout << endl;
	}
	return 0;
}