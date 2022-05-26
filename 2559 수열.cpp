// https://www.acmicpc.net/problem/2559

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	//vector<int> arr(N);
	//for (int i = 0; i < N; ++i) 
	//	cin >> arr[i];
	//
	//int sum = 0, ans;
	//for (int i = 0; i < K; ++i)
	//	sum += arr[i];
	//ans = sum;

	//// 투포인터 활용
	//int p1 = 0, p2 = K - 1;
	//while (true) {
	//	p2++;
	//	if (p2 == N) break;

	//	sum -= arr[p1];
	//	sum += arr[p2];
	//	ans = max(ans, sum);

	//	p1++;
	//}

	//cout << ans << endl;

	// 구간 합 활용
	int temp, psum[100001] = { 0 }, ret = -10000004;
	
	for (int i = 1; i <= N; ++i) {
		cin >> temp;
		psum[i] = psum[i - 1] + temp;
	}
	for (int i = K; i <= N; ++i) {
		ret = max(ret, psum[i] - psum[i - K]);
	}
	cout << ret << endl;

	return 0;
}