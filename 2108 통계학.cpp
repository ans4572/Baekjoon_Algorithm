/*
반올림 함수: round() / 올림 함수: ceil() / 내림 함수: floor()
최빈값을 찾고 정렬을 하기 위해 계수 정렬 사용.
음수도 고려해야 하므로 count배열 만들 때 8001개를 만들고 -4000~4000
순으로 저장하여 계산함.
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> vec;
	vector<int> count(8001,0);   //-4000~4000 수 개수 카운트 벡터

	int num;
	int sum = 0;                 //산술 평균 구하기 위한 N개의 수들의 합
	int min = 4001, max = -4001; //범위를 구하기 위한 최솟값과 최댓값
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		sum += num;         
		if (num > max)
			max = num;
		if (num < min)
			min = num;
		vec.push_back(num);
		count[num + 4000]++;   //count[0] => -4000 , count[8000] => 4000 이다.
	}

	//최빈값 찾기
	int maxFrequency = 0;
	bool second = false;   //여러개 있는 최빈값 중 두 번째로 작은 값을 찾기 위한 bool타입
	int secondFrequency;
	for (int i = 1; i <= 8000; ++i)
	{
		if (count[i] > count[maxFrequency]) {
			//더 큰 값을 찾았다면 second를 이미 구했을 경우를 위해 다시 false로 바꿔준다.
			second = false;
			maxFrequency = i;
		}
		//가장 큰 값과 같으면서 두 번째로 작은 값을 찾은 경우
		else if (count[i] == count[maxFrequency] && second == false) {
			second = true;
			secondFrequency = i;
		}
	}

	sort(vec.begin(), vec.end());

	cout << round((double)sum / N) << endl;
	cout << vec[N / 2] << endl;
	if (second == false)
		cout << (maxFrequency - 4000) << endl;
	else
		cout << (secondFrequency - 4000) << endl;
	cout << abs(max - min) << endl;

	return 0;
}