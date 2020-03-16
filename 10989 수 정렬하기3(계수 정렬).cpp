/*
문제 자체가 메모리 사용량이 적으므로 일반적인 계수정렬로 풀 수가 없음.
c++에서 입출력 시간을 줄이기 위해 
cin.tie(NULL);
ios_base::sync_with_stdio(false);
두 가지를 사용하고 endl대신 \n사용.
*/
#include<iostream>

#include<vector>

using namespace std;

//void countingSort(vector<int> &arr,const int &max)
//{
//	vector<int> count(max + 1); //1부터 시작이므로 +1
//	vector<int> result(arr.size());
//
//	//0으로 초기화
//	for (int i = 0; i < count.size(); ++i)
//		count[i] = 0;
//	
//	//각 숫자의 갯수만큼 저장
//	for (int i = 0; i < arr.size(); ++i)
//		count[arr[i]]++;
//
//	//누적합 저장
//	for (int i = 1; i < count.size()-1; ++i)
//	{
//		count[i + 1] += count[i];
//	}
//	
//	//결과 배열에 저장 후 해당 누적합 - 1
//	for (int k = arr.size() - 1; k >= 0; --k)
//	{
//		result[count[arr[k]]-1] = arr[k];
//		count[arr[k]]--;
//	}
//
//	//복사
//	for (int i = 0; i < arr.size(); ++i)
//		arr[i] = result[i];
//}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int n;
	vector<int> count(10001);

	//개수 0으로 초기화
	for (int i = 0; i < 10001; ++i)
		count[i] = 0;

	//입력받고 그 수의 개수 증가
	for (int i = 0; i < N; ++i)
	{
		cin >> n;
		count[n]++;
	}
	
	for (int j = 1; j < count.size(); ++j)
	{
		int n = count[j];
		if (n > 0) {
			while (n > 0) {
				cout << j << "\n";
				n--;
			}
		}
	}

	return 0;
}