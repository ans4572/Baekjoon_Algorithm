#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N, H;
	cin >> N >> H;

	//각 높이별 석순과 종유석의 개수 저장
	vector<int> bottom(H + 1,0); //석순
	vector<int> top(H + 1,0);    //종유석

	int h;
	for (int i = 0; i < N / 2; ++i) {
		cin >> h;
		bottom[h]++;
		cin >> h;
		top[H - h + 1]++;  //h높이라면 밑에서부터 H-h+1 높이부터 등장
	}

	//부분합 구하기
	for (int i = 1; i < H; ++i) {
		top[i + 1] += top[i];
		bottom[H - i] += bottom[H - i + 1];
	}
	
	//높이 1부터 H까지 개수 세서 최소값 구하기
	int sum, ans = 200001, ansCount = 0;
	for (int i = 1; i <= H; ++i) {
		sum = bottom[i] + top[i];
		if (ans == sum) 
			ansCount++;
		else if (ans > sum) {
			ans = sum;
			ansCount = 1;
		}
	}

	cout << ans << " " << ansCount << endl;

	return 0;
}