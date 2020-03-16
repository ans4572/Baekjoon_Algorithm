#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long K, N;
	cin >> K >> N;

	vector<long long> vec(K);

	long long max = 0;
	long long left = 1, right, mid = 0;
	//벡터 값 설정 및 최대값(right) 찾기
	for (int i = 0; i < K; ++i)
	{
		cin >> vec[i];
		if (i == 0)
			right = vec[i];
		else if (right < vec[i])
			right = vec[i];
	}

	long long count = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		count = 0;
		for (int i = 0; i < K; ++i)
			count += vec[i] / mid;

		if (count >= N)
		{
			if (max < mid)
				max = mid;
			left = mid + 1;
		}
		else if (count < N)
		{
			right = mid - 1;
		}
	}

	cout << max << "\n";

	return 0;
}